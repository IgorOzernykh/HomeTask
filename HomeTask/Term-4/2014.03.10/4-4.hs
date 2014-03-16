checkUnequality :: (Eq a) => [a] -> Bool
checkUnequality [] = True
checkUnequality (x:xs)  | (filter (== x) xs == []) = checkUnequality xs
                        | otherwise = False            
main = do
       putStrLn(show $ checkUnequality [1, 2, 3, 4, 5, 6, 7, 94])
       putStrLn(show $ checkUnequality [1, 2, 3, 5, 7, 9, 2])
       putStrLn(show $ checkUnequality ["abc", "qwe", "dasd" ])
       putStrLn(show $ checkUnequality ["abc", "qwe", "dasd", "abc"])
       putStrLn(show $ checkUnequality ['a', 'b', 'c', 'd', 'a', 'e'])
       putStrLn(show $ checkUnequality ['q','w','e','r','t','y'])