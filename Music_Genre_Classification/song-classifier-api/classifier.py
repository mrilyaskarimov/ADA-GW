import json
import math
import os
import pickle
from os import listdir
from os.path import isfile, join

import librosa
import librosa.display
import numpy as np
from pydub import AudioSegment

# Constants
LABELS = [
    "pop",
    "metal",
    "disco",
    "blues",
    "mugam",
    "reggae",
    "classical",
    "rock",
    "hiphop",
    "country",
    "jazz"
]

JSON_PATH = "generated/tmp.json"
WAV_PATH = "generated/wav"

SAMPLE_RATE = 22050
DURATION = 30 # in seconds
SAMPLES_PER_TRACK = SAMPLE_RATE*DURATION # 22050 * 30
NUM_SEGMENTS = 30

MODEL_PATH = "static/model(75,75).pkl"


def __write_as_wav(new_songs_path, wav_songs_path, genre="empty."):
    # Find those song files
    print("---->", listdir(new_songs_path))
    onlyfiles = [f for f in listdir(new_songs_path) if isfile(join(new_songs_path, f))]

    numb = 100
    audio_length = 30 * 1000  # in milliseconds, 30 seconds
    for f in onlyfiles:
        filename = os.fsdecode(f)
        if filename.endswith(".mp3") or filename.endswith(".MP3"):
            xpath = os.path.join(new_songs_path, filename)
            print(xpath)
            new = os.path.join(os.path.join(wav_songs_path), genre + str(numb).zfill(5) + ".wav")
            aud_seg = AudioSegment.from_mp3(xpath)
            aud_seg = aud_seg[0:audio_length]
            aud_seg = aud_seg.set_frame_rate(22050)
            aud_seg.export(new, format="wav")
            numb = numb + 1

# num_segments is needed for NN, which needs chunks of data, rather than one full segment.
def __clear_files(genre):
    for file in os.listdir(os.path.join(WAV_PATH, genre)):
        os.remove(os.path.join(WAV_PATH, genre, file))
    for file in os.listdir(os.path.join("upload", genre)):
        os.remove(os.path.join("upload", genre, file))

def __save_as_mfcc(dataset_path, json_path, num_mfcc=13, n_fft=2048, hop_length=512, num_segments=10):
    data = {
        "mapping": [],
        "mfcc": [],
        "labels": []
    }
    # overall number of samples per track

    num_samples_per_segment = int(SAMPLES_PER_TRACK / num_segments)  # 22050 * 30 / 10
    expected_num_mfcc_vectors_per_segment = math.ceil(
        num_samples_per_segment / hop_length)  # calculating mfcc by the hop_length (fourier shifting) and we need to ceil the value
    print(expected_num_mfcc_vectors_per_segment)
    # looping through all the genres and
    # dirpath - current, dirnames - subfolders, filenames - all file names
    for i, (dirpath, dirnames, filenames) in enumerate(os.walk(dataset_path)):

        # ensure that we're not att he root level
        if dirpath is not dataset_path:

            # save the semantic label, save the semantic (genre) levels
            dirpath_components = dirpath.split("/")  # genre/blues will give us ["genre_original", "blues"]
            semantic_label = dirpath_components[-1]  # consider the last, which is blues
            data["mapping"].append(semantic_label)
            print("\nProcessing {}".format(semantic_label))

            # process files for a specific genre
            for f in filenames:
                print(f)
                # load audio file
                file_path = os.path.join(dirpath, f)  # file path for the audio file
                if not file_path.endswith('.DS_Store'):
                    signal, sr = librosa.load(file_path, sr=SAMPLE_RATE)

                    # process segments extracting mfcc and storing data
                    for s in range(num_segments):
                        start_sample = num_samples_per_segment * s  # s=0 -> 0
                        finish_sample = start_sample + num_samples_per_segment  # s=0 -> num_samples_per_segment

                        mfcc = librosa.feature.mfcc(signal[start_sample:finish_sample], sr, n_mfcc=num_mfcc,
                                                    n_fft=n_fft, hop_length=hop_length)

                        mfcc = mfcc.T

                        # store mfcc for segment if it has the expected length
                        if len(mfcc) == expected_num_mfcc_vectors_per_segment:
                            data["mfcc"].append(mfcc.tolist())
                            data["labels"].append(i - 1)
                            print("{}, segment:{}".format(file_path, s + 1))

    with open(json_path, "w") as fp:
        json.dump(data, fp, indent=4)


def __test_song(current_song_path, next_path, genre, object_file):
    __write_as_wav(current_song_path, (next_path + "/" + genre), genre)
    __save_as_mfcc(next_path, JSON_PATH, num_segments=NUM_SEGMENTS)

    with open(JSON_PATH, "r") as fp:
        test_data = json.load(fp)
    arr = np.array(test_data)
    test_mfcc = np.array(test_data["mfcc"])
    test_targets = np.array(test_data["labels"])
    index = 0

    length_of_array = len(test_mfcc)
    print(length_of_array)
    while index != len(test_mfcc) - 1:
        print(index, len(test_mfcc))
        if (0.0 in test_mfcc[index]):
            test_mfcc = np.delete(test_mfcc, index, 0)
            test_targets = np.delete(test_targets, index, 0)
            index = index - 1
        index = index + 1
    #     for i in range(len(test_mfcc)):
    #         print(0.0 in test_mfcc[i])
    # evaluating model

    results = []
    predict_X = test_mfcc
    predict_Y = test_targets

    predict_X.shape

    # perform prediction
    # print(X_to_predict)
    for i in predict_X:
        i = i[np.newaxis, ...]  # array shape (1, 130, 13, 1)
        prediction = object_file.predict(i)
        index_predicted = np.argmax(prediction, axis=1)
        for k in index_predicted:
            results.append(LABELS[k])
            print("target:", LABELS[predict_Y[k]])
            print("predicted: ", k, " mfcc: ", LABELS[k])

    result_dict = {x: results.count(x) for x in results}
    print(result_dict)
    
    __clear_files(genre)
    
    genre = max(result_dict, key=lambda x: result_dict[x])

    print("Genre is: ", genre)

    return genre


def classify_song(genre):
    file = open(MODEL_PATH, 'rb')
    object_file = pickle.load(file)
    return __test_song(f"upload/{genre}", WAV_PATH, genre, object_file)
