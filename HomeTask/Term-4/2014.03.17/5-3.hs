allComb :: Int -> [[Int]]
allComb 1 = [[1], [2], [3]]
allComb n = [[x] ++ y | x <- [1,2,3], y <- allComb (n - 1)]

main = do
    putStrLn (show $ allComb 2)
    putStrLn (show $ allComb 3)