class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        if (image.size() == 0) return image;
        if (image[0].size() == 0) return image;
        int prevColor = image[sr][sc];
        if (prevColor != newColor)
            fill(image,sr, sc, prevColor, newColor);
        return image;
    }
    void fill(vector<vector<int>>& image, int sr, int sc, int prevColor, int newColor) //dfs logic
    {
        if (sr<0||sr>= image.size()||sc<0||sc>=image[0].size()||image[sr][sc] != prevColor) return;
        image[sr][sc] = newColor;
        fill(image,sr-1, sc, prevColor, newColor);
        fill(image,sr+1, sc, prevColor, newColor);
        fill(image,sr, sc-1, prevColor, newColor);
        fill(image,sr, sc+1, prevColor, newColor);
    }
    
};
