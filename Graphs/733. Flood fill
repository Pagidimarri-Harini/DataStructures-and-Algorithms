class Solution:
    def fill(self,image,sr,sc,color,oldcolor):
        if (sr < 0 or sr > len(image)-1) or (sc < 0 or sc > len(image[0])-1) or image[sr][sc] != oldcolor or image[sr][sc] == color:
            return image
        image[sr][sc] = color
        image = self.fill(image,sr,sc-1,color,oldcolor)
        image = self.fill(image,sr,sc+1,color,oldcolor)
        image = self.fill(image,sr-1,sc,color,oldcolor)
        image = self.fill(image,sr+1,sc,color,oldcolor)
        return image
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        return self.fill(image,sr,sc,color,image[sr][sc])
        
        
