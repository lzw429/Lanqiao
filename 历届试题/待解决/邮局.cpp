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
double dis_min = INT_MAX;

bool cmp(Post p1, Post p2) {
    return p1.dis < p2.dis;
}

double dis(Post p,House h)
{
    return sqrt(abs(p.x-h.x)+abs(p.y-h.y));
}

double sumDis() {
    double ret=0; // 返回每户村民到最近邮局的距离和
    for(vector<House>::iterator h=house.begin();h!=house.end();++h )
    {
        double tmp_dis=INT_MAX; // 这户村民到最近邮局的距离
        for(vector<Post>::iterator p = post.begin();p!=post.end();++p)
        {
            double t= dis(*p,*h);
           if(t<tmp_dis)
                tmp_dis=t;
        }
        ret+=tmp_dis;
    }
   return ret;
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
        if(post.size()<k)
        {
            post.push_back(Post{x, y, i + 1,0});
           int s = sumDis();
           if(s<dis_min)
            dis_min=s;
           else
            post.pop_back();
        }
        else {
            int rep=-1;
            double tmp_min=dis_min;
            Post input = Post{x,y,i+1,0};
            for(int j=0;j<k;++j)
            {
                Post p = post[j];
                post[j] = input;
                double s=sumDis();
                if(s<tmp_min)
                    rep=j;
                post[j] = p;
            }
            if(rep!=-1)
               {
                   post[rep]=input};
                   dis_min=tmp_min;
               }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << post[i].num << " ";
    }
    return 0;
}
