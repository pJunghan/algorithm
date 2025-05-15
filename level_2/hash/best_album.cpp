#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//vector<int> solution(vector<string> genres, vector<int> plays) {
//    vector<int> answer;
//    unordered_map<string, int> album;
//
//    for (int i = 0; i < genres.size(); i++) {
//        album[genres[i]] += plays[i];
//    }
//
//    vector<pair<string, int>> sorted_album(album.begin(), album.end());
//    sort(sorted_album.begin(), sorted_album.end(),
//        [](const pair<string, int>& a, const pair<string, int>& b) {
//            return a.second > b.second;
//        });
//
//    for (int genre_rank = 0; genre_rank < 2 && genre_rank < (int)sorted_album.size(); genre_rank++) {
//        string genre = sorted_album[genre_rank].first;
//        int first = -1, second = -1;
//
//        for (int i = 0; i < genres.size(); i++) {
//            if (genres[i] == genre) {
//                if (first == -1 || plays[i] > plays[first]) {
//                    second = first;
//                    first = i;
//                }
//                else if (second == -1 || plays[i] > plays[second]) {
//                    second = i;
//                }
//            }
//        }
//
//        if (first != -1) answer.push_back(first);
//        if (second != -1) answer.push_back(second);
//    }
//
//    return answer;
//}
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare_album(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

bool compare_song(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> albums;//장르명, 재생 수 저장 [시간복잡도 : O(N)][공간복잡도 : unordered_map<string, int> → O(G)]
    unordered_map<string, vector<pair<int, int>>> genre_songs; //재생 수,인덱스 쌍 저장 [공간복잡도 : unordered_map<string, vector<pair<int, int>>> → O(N)]
    vector<pair<string, int>> max_albums; //재생 수 별 정렬을 위한 벡터 [공간복잡도 : vector<pair<string, int>> → O(G)]

    //장르 별 총 재생 수 정렬 [시간 복잡도 : O(G \log G)]
    for (int i = 0; i < genres.size(); i++) {
        albums[genres[i]] += plays[i];
        genre_songs[genres[i]].push_back({ plays[i], i });
    }

    //장르별 상위 2곡 뽑기 [시간복잡도 : O(N \log N)]
    for (auto& album : albums) {
        max_albums.push_back(album);
    }

    sort(max_albums.begin(), max_albums.end(), compare_album);

    //총 재생수 1,2위곡 각각 상위 2곡 뽑기
    for (auto& album : max_albums) {
        string genre = album.first;
        vector<pair<int, int>>& songs = genre_songs[genre];

        sort(songs.begin(), songs.end(), compare_song);

        for (int i = 0; i < songs.size() && i < 2; i++) {
            answer.push_back(songs[i].second);
        }
    }

    return answer; // [공간복잡도 : 최대 2곡 × G → O(G)]
}
/*
시간 복잡도 : O(N+GlogG+NlogN)=O(NlogN)

공간 복잡도 : O(N+G)=O(N)
*/
int main() {
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    vector<int> result = solution(genres, plays);

    cout << "Best album song indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
