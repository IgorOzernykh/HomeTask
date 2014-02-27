sumDigit :: Int -> Int
sumDigit 0 = 0
sumDigit n = (mod n 10) + sumDigit (div n 10)

