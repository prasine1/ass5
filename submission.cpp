#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define PICS 20
#define CATEGORIES 3
#include <algorithm>
   
struct gph
{
    vector<vector<int> > edges;
    int vertices;
};
   
struct d_set
    {
      int *parent;
      int *rank;
    };
   
    void addEdge(struct gph &g, int x, int y, int w)
    {
      x = x - 1;
      y = y - 1;
      g.edges.push_back({w, x, y});
    }
   
    bool cw(vector<int> i1, vector<int> i2)
    {
      return (i2[0] < i1[0]);
    }
   
    int find_mst(struct d_set &s, int i)
    {
   
     
      if (s.parent[i] == -1)
      {
        return i;
      }
      return s.parent[i] = find_mst(s, s.parent[i]);
    };
   
    void mst1(struct d_set &s, int x, int y)
    {
      int set1 = find_mst(s, x);
      int set2 = find_mst(s, y);
   
      if (set1 != set2)
      {
        if (s.rank[set1] < s.rank[set2])
        {
          s.parent[set1] = set2;
          s.rank[set1] += s.rank[set2];
        }
        else
        {
          s.parent[set2] = set1;
          s.rank[set1] += s.rank[set2];
        }
      }
    }
    int mstNS(struct d_set &s) //vxcv
    {
      set<int> total_sets;
      int i = 0;
      while(i< PICS)
      {
          total_sets.insert(find_mst(s, i));
          i++;
      }
     
      return total_sets.size();
    }
   
    void category(struct d_set &s)

    {
      map<int, vector<int> > categories;
      int i = 0;
      while(i< PICS)
      {
          int categ = find_mst(s, i);
        if (categories.find(categ) == categories.end())
        {
          categories.insert(pair<int, vector<int> >(categ, {i}));
        }
        else
        {
          categories[categ].push_back(i);
        }
         
          i++;
      }
     
      map<int, vector<int> >::iterator it;
   
      int j = 1;
      for (it = categories.begin(); it != categories.end(); it++)
      {
        cout << "for Category " << j  << endl
             << endl;
        for (int i = 0; i < it->second.size(); i++)
        {
          cout << "p" << it->second[i] + 1 <<" ";
        }
        j++;
        cout << endl<<"\n";
      }
    }
    void mst(struct gph &g)
    {
      sort(g.edges.begin(), g.edges.end(), cw);
      struct d_set s;
   
      s.parent = new int[PICS];
      s.rank = new int[PICS];
  
        int i = 0;
      while(i< PICS)
      {
          s.parent[i] = -1;
        s.rank[i] = 1;
          i++;
      }
     
   
      int p = 0;
      for (int i = 0; i < g.edges.size(); i++)
      {
        int w = g.edges[i][0];
        int x = g.edges[i][1];
        int y = g.edges[i][2];
   
        if (find_mst(s, x) != find_mst(s, y))
        {
          if (mstNS(s) == CATEGORIES)
          {
            category(s);
          }
          mst1(s, x, y);
         
         
          p += w;
        }
      }
    }
   
    int main()
    {
      struct gph g;
      g.vertices = PICS;
   
     
      addEdge(g, 1, 2, 80);
     
      addEdge(g, 5, 9, 73);
     
      addEdge(g, 9, 13, 69);
     
      addEdge(g, 2, 3, 10);
     
      addEdge(g, 5, 7, 20);
     
      addEdge(g, 5, 2, 74);
     
      addEdge(g, 9, 18, 15);
     
      addEdge(g, 13, 14, 21);
     
      addEdge(g, 9, 1, 92);
     
      addEdge(g, 13, 2, 59);
     
      addEdge(g, 20, 4, 6);
     
      addEdge(g, 18, 17, 17);
     
      addEdge(g, 11, 3, 74);
     
      addEdge(g, 7, 18, 83);
     
      addEdge(g, 7, 12, 27);
     
      addEdge(g, 1, 10, 16);
     
      addEdge(g, 5, 15, 47);
     
      addEdge(g, 20, 14, 94);
     
      addEdge(g, 14, 18, 77);
     
      addEdge(g, 2, 4, 30);
     
      addEdge(g, 11, 14, 62);
     
      addEdge(g, 3, 20, 85);
     
      addEdge(g, 11, 7, 62);
     
      addEdge(g, 6, 10, 87);
     
      addEdge(g, 12, 15, 81);
     
      addEdge(g, 3, 19, 39);
     
      addEdge(g, 9, 8, 45);
     
      addEdge(g, 19, 4, 65);
     
      addEdge(g, 8, 16, 70);
     
      addEdge(g, 15, 17, 64);
     
      addEdge(g, 1, 11, 32);
     
      addEdge(g, 11, 6, 43);
     
      addEdge(g, 12, 6, 87);
     
      addEdge(g, 12, 19, 70);
     
      addEdge(g, 7, 16, 39);
     
      addEdge(g, 13, 6, 22);
     
      addEdge(g, 4, 16, 68);
     
      addEdge(g, 17, 10, 56);
     
      addEdge(g, 19, 15, 71);
   
      mst(g);
    }