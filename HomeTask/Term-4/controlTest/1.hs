primeList = [x | x <- [2..], (product [1..(x - 1)] + 1) `mod` x == 0]

main = do
    putStrLn (show $ take 100 primeList)