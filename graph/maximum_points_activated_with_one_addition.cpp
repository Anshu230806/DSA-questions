// below solution not work because there contains negative points in it 

class DisjointSet{
    public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1 , 0);
        size.resize(n+1 , 1);
        parent.resize(n+1);
        for(int i= 0; i<= n ;i++){
            parent[i] = i;
        }
    }

    int findUPar(int n){
        if(n == parent[n] ) return n;
        return parent[n] = findUPar(parent[n]);
    }

    void unionBySize(int u , int v){
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(ult_u == ult_v) return ;
        if(size[ult_u] >= size[ult_v]){
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        else{
             parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
    }

};

class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        int maxRow = 0;
        int maxCol =0;
        for(int i = 0 ; i< n; i++){
            maxRow = max( maxRow , points[i][0]);
            maxCol = max(maxCol ,points[i][1] );
        }

        DisjointSet dis(maxRow+maxCol+2);

        for(int i =0 ; i< n ;i++){
            int row = points[i][0];
            int updated_col = points[i][1]+maxRow;
            dis.unionBySize(row , updated_col);
        }

        int lar = 0;
        int sec =0;
        unordered_map<int , int>mpp ;
        for(int i = 0 ;i < points.size() ; i++){
            int row = points[i][0];
            int par = dis.findUPar(row);
            if(mpp.find(row) == mpp.end() && row == par   && dis.size[row] > lar){
                sec = lar;
                lar = dis.size[row]-1;
            }
            else if(mpp.find(row) == mpp.end() && row == par &&  dis.size[row] <= lar && dis.size[row] > sec){
                sec = dis.size[row]-1;
            }
            mpp[row] = 1;
        }
       // if(sec == 0 ) return n+1;

        return lar+sec+1;
    }
};




// corrected solution 


class DisjointSet{
    public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1 , 0);
        size.resize(n+1 , 1);
        parent.resize(n+1);
        for(int i= 0; i<= n ;i++){
            parent[i] = i;
        }
    }

    int findUPar(int n){
        if(n == parent[n] ) return n;
        return parent[n] = findUPar(parent[n]);
    }

    void unionBySize(int u , int v){
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(ult_u == ult_v) return ;
        if(size[ult_u] >= size[ult_v]){
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        else{
             parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
    }

};

class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();

        
       DisjointSet dis(n);
       unordered_map<int , int>xmap;
       unordered_map<int, int>ymap;
       for(int i = 0 ; i< n ;i++){
          int row = points[i][0];
          int col = points[i][1];
          if(xmap.find(row) == xmap.end() && ymap.find(col) == ymap.end()){
            xmap[row] = i;
            ymap[col] = i;
          }
          else if(xmap.find(row) != xmap.end() && ymap.find(col) == ymap.end() ){
            dis.unionBySize( i , xmap[row]);
            ymap[col] = i;
          }
          else if (xmap.find(row) == xmap.end() && ymap.find(col) != ymap.end() ){
            dis.unionBySize( i , ymap[col]);
            xmap[row] = i;
          }
          else{
             dis.unionBySize( i , xmap[row]);
              dis.unionBySize( i , ymap[col]);
          }
       }

       int len =0;
       int sec =0;
       for(int i= 0; i< n;i++){
        int par = dis.findUPar(i);
        if(i == par){
            if(dis.size[i] > len){
                sec = len ;
                len = dis.size[i];
            }
            else if(dis.size[i] > sec){
                sec = dis.size[i];
            }
         }
       }
       return len+sec+1;
    }
};