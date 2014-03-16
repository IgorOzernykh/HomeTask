evenCount1 :: [Int] -> Int
evenCount1 = length . (filter $ (==0) . (`mod` 2))
evenCount2 :: [Int] -> Int
evenCount2 = (foldr (+) 0) . (map $ (`mod` 2) . (+ 1))
evenCount3 :: [Int] -> Int
evenCount3 = length . (filter (==0) . (map $ (`mod` 2)))

main = do
    putStrLn(show $ evenCount1 [1, 2, -3, -4, 5, 6, -7, -8, 9, 10, -11])
    putStrLn(show $ evenCount2 [1, 2, -3, -4, 5, 6, -7, -8, 9, 10, -11])
    putStrLn(show $ evenCount3 [1, 2, -3, -4, 5, 6, -7, -8, 9, 10, -11])