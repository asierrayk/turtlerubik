Cube Representation
===================

The representation of the rubik's cube is as follows.
- Each piece has a unique identifier and an orientation.
- The identifier is a number with a value between 0 and 26.
- The id value expressed in base 3 represents the coordenate of the piece in a tridimensional space.
- The orientation is a number between 0 and 2 for corners and between 0 and 1 for edges.
- The orientation number represent the number of clockwise turns needed in order to get the leader sticker of the piece facing to the corresponding leader face.


Leader Faces
============

- Up face and Down face are considered primary leader faces.
- Front face and Back face are the secondary leader faces.
- The leader face for certain position is the primary face which contains that postion, if there are is primary face containing that position, then the leader face is the secondary face containing that position.
- The leader sticker of a piece is the one contained in the leader face of its position when the cube is solved.
- For corners only primary leader faces are necessary.
- For edges the leader face is one of the primaries if the piece is one of these faces, otherwise the leader face is one of the secondaries.

                      ______ ______ ______
                     |      |      |      | 
                     |   0  |   1  |   2  |
                     |______|______|______|
                     |      |      |      | 
                     |   9  |  10  |  11  | UP
                     |______|______|______|
                     |      |      |      | 
         LEFT        |  18  |  19  |  20  |        RIGHT               BACK
 ______ ______ ______|______|______|______|______ ______ ______ ______ ______ ______
|      |      |      |      |      |      |      |      |      |      |      |      |
|   0  |   9  |  18  |  18  |  19  |  20  |  20  |  11  |   2  |   2  |   1  |   0  |
|______|______|______|______|______|______|______|______|______|______|______|______|
|      |      |      |      |      |      |      |      |      |      |      |      | 
|   3  |  12  |  21  |  21  |  22  |  23  |  23  |  14  |   5  |   5  |   4  |   3  |
|______|______|______|______|______|______|______|______|______|______|______|______|
|      |      |      |      |      |      |      |      |      |      |      |      | 
|   6  |  15  |  24  |  24  |  25  |  26  |  26  |  17  |   8  |   8  |   7  |   6  |
|______|______|______|______|______|______|______|______|______|______|______|______|
                     |      |      |      | 
                     |  24  |  25  |  26  |
                     |______|______|______|
                     |      |      |      | 
                     |  15  |  16  |  17  | DOWN
                     |______|______|______|
                     |      |      |      | 
                     |   6  |   7  |   8  |
                     |______|______|______|

0 1 2 
3 4 5 
6 7 8 

9 10 11 
12 13 14 
15 16 17 

18 19 20 
21 22 23 
24 25 26
           

					
					
					
					
					____________ x (1,0,0)
                                       /| 
                                      / |
                           (0,0,1) z /  |
                                        |
                                        |
                                        | y (0,1,0)









                                  (0,0,0) 
                                         _____________
				       /|            /| (2,0,0)
				      /	|   (2,0,2) / |
			    (0,0,2)  /____________ /  |
                                    |	|         |   |
				    |	|         |   |           CORNERS
			            |	|_________|___| (2,2,0)
                                    |  /(0,2,0)   |  /
                                    | /           | /
                                    |/____________|/ (2,2,2)

                                    (0,2,2)


                                         _____________
				       /|            /|        
				      /	|           / |
			             /____________ /  |
                                    |	|         |   |
				    |	|         |   |           EDGES
			            |	|_________|___|        
                                    |  /          |  /
                                    | /           | /
                                    |/____________|/        

