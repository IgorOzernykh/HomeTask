import Control.Monad

firstBiggest :: [Int] -> Maybe Int
firstBiggest [] = Nothing
firstBiggest [_] = Nothing
firstBiggest [_, _] = Nothing
firstBiggest (x:y:z:zs) = return zs >>= (\xs -> 
                                        if (x < y) && (y > z) then 
                                            Just y 
                                        else firstBiggest (y:z:xs))

main = do
    putStrLn (show $ firstBiggest [1, 2, 3, 4, 5, 6, 7])
    putStrLn (show $ firstBiggest [1, 2, 3, 5, 4, 8, 7, 10, 9])

