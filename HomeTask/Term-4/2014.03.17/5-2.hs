satisfy :: (a -> Bool) -> [a] -> Bool
satisfy cond [] = True
satisfy cond (x:xs) | cond x = satisfy cond xs
                    | otherwise = False
main = do
    putStrLn (show $ satisfy (>10) [11, 12, 13, 15, 42])
    putStrLn (show $ satisfy (>10) [11, 2, 13, 15, 42])
    putStrLn (show $ satisfy even [2, 4, 10, 112, 146, 1024])
    putStrLn (show $ satisfy even [10, 20, 30, 5, 12, 8])