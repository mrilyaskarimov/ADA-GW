from fastapi import FastAPI, File, UploadFile, Form

from classifier import classify_song

app = FastAPI()


@app.get("/health")
def health_check():
    return {"status": "OK"}


@app.post("/api/v1/classify-song")
async def classify_uploaded_song_file(
        genre: str = Form(...),
        song: UploadFile = File(...)
):
    file_location = f"upload/{genre}/{song.filename}"
    with open(file_location, "wb+") as file_object:
        file_object.write(song.file.read())

    classified_genre = classify_song(genre)

    return {"genre": classified_genre}
