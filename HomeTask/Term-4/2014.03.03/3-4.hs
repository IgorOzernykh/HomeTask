firstPos :: [Int] -> Int -> Int
firstPos [] _ = error "No such element!"
firstPos (x:xs) n  
		| x == n = 0
		| otherwise = (firstPos xs n) + 1

maxSumPos :: [Int] -> Int
maxSumPos [] = -1
maxSumPos l = firstPos xs (foldr max (head xs) xs)
				where xs = zipWith (+) l (0 : l)


main = do 
	putStrLn(show $ maxSumPos [1,5,6,2])