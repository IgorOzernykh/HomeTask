data Monomial a = Monomial (a, Int)
            deriving Eq

instance (Show a, Num a, Eq a) => Show (Monomial a)
    where show (Monomial (0, _)) = "0"
          show (Monomial (c, 0)) = show c
          show (Monomial (1, 1)) = "x"
          show (Monomial (c, 1)) = show c ++ "x"
          show (Monomial (1, d)) = "x^" ++ show d
          show (Monomial (c, d)) = show c ++ "x^" ++ show d

data Polynomial a = Polynomial [Monomial a]
            deriving Eq

instance (Show a, Num a, Eq a) => Show (Polynomial a)
    where show (Polynomial []) = "0"
          show (Polynomial (x:[])) = show x
          show (Polynomial (x:xs)) = show x ++ "+" ++ show (Polynomial xs)

polToList :: Polynomial a -> [Monomial a]                                                    
polToList (Polynomial a) = a

simplifyPol :: (Eq a, Num a) => Polynomial a -> Polynomial a          
simplifyPol (Polynomial (Monomial p : [])) |fst p == 0 = Polynomial []
                                           | otherwise = Polynomial [Monomial p]
simplifyPol (Polynomial (Monomial p : ps)) | fst p == 0 = Polynomial $ polToList $ simplifyPol $ Polynomial ps
                                           | otherwise = Polynomial $ (Monomial p) : polToList (simplifyPol $ Polynomial ps)          

addMM :: Num a => Monomial a -> Monomial a -> Polynomial a
addMM (Monomial a) (Monomial b) | snd a == snd b = Polynomial [Monomial (fst a + fst b, snd a)]
                                | snd a > snd b = Polynomial [Monomial a, Monomial b]
                                | otherwise = Polynomial [Monomial b, Monomial a]

multMM :: Num a => Monomial a -> Monomial a -> Monomial a
multMM (Monomial a) (Monomial b) =  Monomial (fst a * fst b, snd a + snd b)

addPM :: Num a => Polynomial a -> Monomial a -> Polynomial a
addPM (Polynomial []) (Monomial m) = Polynomial [Monomial m]
addPM (Polynomial (Monomial p : ps)) (Monomial m) | snd p == snd m = Polynomial $ Monomial (fst p + fst m, snd p) : ps
                                                  | snd p > snd m = Polynomial $ Monomial p : (polToList $ addPM (Polynomial ps) (Monomial m))
                                                  | otherwise = Polynomial $ Monomial m : Monomial p : ps

addPP :: Num a => Polynomial a -> Polynomial a -> Polynomial a
addPP (Polynomial []) (Polynomial r) = (Polynomial r)
addPP (Polynomial (Monomial p : ps)) (Polynomial r) = addPP (Polynomial ps) (addPM (Polynomial r) (Monomial p)) 

multPM :: Num a => Polynomial a -> Monomial a -> Polynomial a
multPM (Polynomial []) _ = Polynomial []
multPM (Polynomial (Monomial p : ps)) (Monomial m) = Polynomial $ multMM (Monomial p) (Monomial m) : (polToList $ multPM (Polynomial ps) (Monomial m)) 

multPP (Polynomial []) _ = Polynomial []
multPP (Polynomial (Monomial p : ps)) (Polynomial r) = addPP (multPM (Polynomial r) (Monomial p)) (multPP (Polynomial ps) (Polynomial r))

(|+) :: (Eq a, Num a) => Monomial a -> Monomial a -> Polynomial a
(Monomial m) |+ (Monomial n) = simplifyPol $ addMM (Monomial m) (Monomial n)
(|*) :: (Eq a, Num a) => Monomial a -> Monomial a -> Polynomial a
(Monomial m) |* (Monomial n) = simplifyPol $ Polynomial [multMM (Monomial m) (Monomial n)]

(+|) :: (Eq a, Num a) => Polynomial a -> Monomial a -> Polynomial a
(Polynomial p) +| (Monomial m) = simplifyPol $ addPM (Polynomial p) (Monomial m)
(*|) :: (Eq a, Num a) => Polynomial a -> Monomial a -> Polynomial a
(Polynomial p) *| (Monomial m) = simplifyPol $ multPM (Polynomial p) (Monomial m)

(|+|) :: (Eq a, Num a) => Polynomial a -> Polynomial a -> Polynomial a
(Polynomial p) |+| (Polynomial r) = simplifyPol $ addPP (Polynomial p) (Polynomial r)

(|*|) :: (Eq a, Num a) => Polynomial a -> Polynomial a -> Polynomial a
(Polynomial p) |*| (Polynomial r) = simplifyPol $ multPP (Polynomial p) (Polynomial r)

main = do
    let p1 = Polynomial [Monomial (4, 5), Monomial (6, 3), Monomial (2, 1)]
    let p2 = Polynomial [Monomial (1, 5), Monomial (3, 3), Monomial (7, 1)]
    let p3 = Polynomial [Monomial (3, 7), Monomial (4, 4), Monomial (2, 2)]
    let m1 = Monomial (4, 6)
    let m2 = Monomial (0, 2)
    putStrLn ("p1 = 4x^5 + 6x^3 + 2x")
    putStrLn ("p2 = x^5 + 3x^3 + 7x")
    putStrLn ("p3 = 3x^7 + 4x^4 + 2x^2")
    putStrLn ("m1 = 4x^6")
    putStrLn ("m2 = 0")
    putStr ("p1 + m1: ")
    putStrLn (show $ p1 +| m1)
    putStr ("p2 + m2: ")
    putStrLn (show $ p2 +| m2)
    putStr ("p1 + p2: ")
    putStrLn (show $ p1 |+| p2)
    putStr ("p1 + p3: ")
    putStrLn (show $ p1 |+| p3)
    putStr ("p1 * p3: ")
    putStrLn (show $ p1 |*| p3)
    putStr ("p1 * m1: ")
    putStrLn(show $ p1 *| m1)
    putStr("p2 * m2: ")
    putStrLn(show $ p2 *| m2)

