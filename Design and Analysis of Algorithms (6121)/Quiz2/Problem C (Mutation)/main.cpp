//
//  main.cpp
//  Problem C (Mutation)
//
//  Created by Ilyas Karimov on 03.12.20.
//

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct segment{
    int index, value;
    segment(int index = -1, int value = -1) : index(index), value(value){};
};

struct segmentFull{
    int value, start, finish;
    segmentFull(int value = -1, int start = -1, int finish = -1) : value(value), start(start), finish(finish){};
};


vector<segment> seg;
vector<segmentFull> segList;
int n, el, start, en,cur, res;

int f(segment a, segment b)
    {
        if(a.value == b.value) return a.index < b.index;
        return a.value < b.value;
    }

int comp(segmentFull a, segmentFull b){
    return a.finish < b.finish;
}

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        scanf("%d", &el);
        seg.push_back(segment(i, el));
    }
    sort(seg.begin(), seg.end(), f);
    
    segment curr, prev, next;
    segmentFull elem;
    
    for(int k = 0; k < n; k++){
        curr = seg[k];
        next = (k+1 < n) ? seg[k+1]: segment();
        
        if(prev.value != curr.value){
            elem.value = curr.value;
            elem.start = curr.index;
        }
        if(curr.value != next.value){
            elem.finish = curr.index;
            segList.push_back(elem);
        }
        prev = curr;
    }
      sort(segList.begin(), segList.end(), comp);
      cur = 0; res = 1;
      for (int k = 1; k < segList.size(); k++)
      {
        if (segList[k].start > segList[cur].finish)
        {
          cur = k;
          res++;
        }
      }

     printf("%d\n", segList.size()- res);
      return 0;

}
