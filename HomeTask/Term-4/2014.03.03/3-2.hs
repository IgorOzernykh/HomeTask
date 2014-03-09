deg2List = 2 : zipWith (+) deg2List deg2List
main = do
	putStrLn(show $ take 10 deg2List)