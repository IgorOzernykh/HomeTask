putBlanks n = do 
           if (n > 0) 
           then do
                putStr(" ")
                putBlanks (n - 1)
            else return() 
            
putStars n = do 
           if (n > 0) 
           then do
                putStr("*")
                putStars (n - 1)
            else return() 
            
printRhom n = printRhomHelper1 n 1
printRhomHelper1 n sn = do
                putBlanks ((n - sn + 1) `div` 2)
                putStars sn
                putStrLn("")
                if (sn < n)
                then do 
                    printRhomHelper1 n (sn + 2)
                else printRhomHelper2 n 1 
printRhomHelper2 n sn = do
                putBlanks ((sn + 1) `div` 2)
                putStars (n - sn - 1)
                putStrLn("")
                if (sn < n)
                then do 
                    printRhomHelper2 n (sn + 2) 
                else return()
