list179 = 1 : 7 : 9 : [10 * x + y | x <- list179, y <- [1,7,9]]
main = do
	putStrLn(show $ take 20 list179)