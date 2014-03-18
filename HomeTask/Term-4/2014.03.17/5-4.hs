multList 1 = [1]
multList n = [1..n] >>= (\x -> map (*x) [1..n])

main = do
    putStrLn (show $ multList 5)
    putStrLn (show $ multList 10)