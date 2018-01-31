#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;
int n, m, k;
struct House {
    int x, y;
};
struct Post {
    int x, y, num;
    double dis;
};

vector <House> house;
vector <Post> post;

bool cmp(Post p1, Post p2) {
    return p1.dis < p2.dis;
}
double dis(House h, Post p) {
    int deltaX=h.x-p.x;
    int deltaY=h.y-p.y;
    return sqrt(deltaX*deltaX+deltaY*deltaY);
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        house.push_back(House{x, y});
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        post.push_back(Post{x, y, i + 1,0});
    }
    for (vector<Post>::iterator i = post.begin(); i != post.end(); ++i) {
        double dis_sum = INT_MAX;
        for (vector<House>::iterator j = house.begin(); j != house.end(); ++j) {
            dis_sum += dis(*j, *i);
        }
        (*i).dis = dis_sum;
    }
    sort(post.begin(),post.end(),cmp);
    for (int i = 0; i < k; i++) {
        cout << post[i].num << " ";
    }
    return 0;
}
