decomp :: Int -> [[Int]]
decomp 0 = [[]]
decomp n = decompHelper n n
decompHelper n k | n > 0 = [1..k] >>= (\x -> map (x:) (decompHelper (n - x) (min x (n - x))))
                 | otherwise = [[]]
                 
main = do
    putStrLn (show $ decomp 5)
    putStrLn (show $ decomp 7)
