import Data.Maybe

data Graph v e = Graph [(Int,v)] [(Int,Int,e)]

first (a, _, _) = a
second (_, b, _) = b
value (_, _, c) = c

numberAndDistance (a,b) = (a, Just b)

findEdge :: Eq t => t -> t -> [(t, t, t1)] -> Maybe (t, t, t1)
findEdge x y [] = Nothing
findEdge x y (z:zs) | (x == first z && y == second z || x == second z && y == first z) = Just z
                    | otherwise = findEdge x y zs

findNearestVertex :: Ord t1 => (t, t1) -> (t, t1) -> (t, t1)
findNearestVertex (a1, b1) (a2, b2) | b1 < b2 = (a1, b1) 
                                    | otherwise = (a2, b2)

infinity = 1 / 0                                    

dijkstra (Graph vs es) root = map numberAndDistance (helper [] (map (\(a, _) -> (a, if a == root then 0 else infinity)) vs))
    where helper visited [] = visited
          helper visited unvisited = helper (minUnvisited : visited) (map recalc (filter (/= minUnvisited) unvisited))
                where minUnvisited = foldr findNearestVertex (head unvisited) (tail unvisited)
                      recalc (num, dist) = recalcHelper $ findEdge num (fst minUnvisited) es
                            where recalcHelper Nothing = (num, dist)
                                  recalcHelper (Just edge) | snd minUnvisited + value edge < dist = (num, snd minUnvisited + value edge) 
                                                           | otherwise =  (num, dist)
                                
main = do
    let g = Graph [(1, 0), (2, 0), (3, 0), (4, 0), (5, 0), (6, 0)] [(1, 2, 7), (1, 3, 9), (1, 6, 14), (2, 3, 10), (2, 4, 15), (3, 4, 11), (3, 6, 2), (4, 5, 6), (5, 6, 9)]
    putStrLn(show $ dijkstra g 1)