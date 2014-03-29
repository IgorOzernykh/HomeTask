data Expression a = Constant a |
                    Variable | 
                    Addition (Expression a) (Expression a) |
                    Subtraction (Expression a) (Expression a) |
                    Multiplication (Expression a) (Expression a) |
                    Division (Expression a) (Expression a) |
                    Degree (Expression a) Int

derivative (Constant _) = Constant 0
derivative Variable = Constant 1
derivative (Addition x y) = Addition (derivative x) (derivative y)
derivative (Subtraction x y) = Subtraction (derivative x) (derivative y)
derivative (Multiplication x y) = Addition (Multiplication x (derivative y)) (Multiplication y (derivative x))
derivative (Degree Variable 1) = Constant 1
derivative (Degree Variable n) = Multiplication (Constant n) (Degree Variable (n - 1))
derivative (Degree x n) = Multiplication (Constant n) (Multiplication (Degree x (n - 1)) (derivative x))
derivative (Division x y) = Division (Subtraction (Multiplication (derivative x) y) (Multiplication x (derivative y))) (Degree y 2)

simplify (Addition a (Constant 0)) = a
simplify (Addition (Constant 0) a) = a
simplify (Subtraction a (Constant 0)) = a
simplify (Subtraction (Constant 0) a) = Multiplication (Constant (-1)) a
simplify (Multiplication a (Constant 1)) = a
simplify (Multiplication (Constant 1) a) = a
simplify (Multiplication _ (Constant 0)) = Constant 0
simplify (Multiplication (Constant 0) _) = Constant 0
simplify (Multiplication (Constant a) (Constant b)) = Constant (a*b)
simplify (Division a (Constant 1)) = a
simplify (Division (Constant 0) _) = Constant 0
simplify (Division _ (Constant 0)) = error "Division by zero"
simplify (Degree (Constant 0) _) = Constant 0 
simplify (Degree _ 0) = Constant 1
simplify (Degree a 1) = a
simplify (Degree (Constant 1) _) = Constant 1
simplify a = a

simplifyExpr (Addition x y) = simplify (Addition (simplifyExpr x) (simplifyExpr y))
simplifyExpr (Subtraction x y) = simplify (Subtraction (simplifyExpr x) (simplifyExpr y))
simplifyExpr (Multiplication x y) = simplify (Multiplication (simplifyExpr x) (simplifyExpr y))
simplifyExpr (Division x y) = simplify (Division (simplifyExpr x) (simplifyExpr y))
simplifyExpr (Degree x n) = simplify (Degree (simplifyExpr x) n)
simplifyExpr a = a

showInBrackets expr = "(" ++ show expr ++ ")"

instance Show a => Show (Expression a) where
            show (Constant a) = show a
            show Variable = "x"
            show (Addition x y) = show x ++ " + " ++ show y
            show (Multiplication x y) = showMult x ++ " * " ++ showMult y
                where showMult (Addition x y) = showInBrackets (Addition x y)
                      showMult (Subtraction x y) = showInBrackets (Subtraction x y)
                      showMult (Division x y) = showInBrackets (Division x y)
                      showMult x = show x
            show (Subtraction x y) = show x ++ " - " ++ showSubt y
                where showSubt (Addition x y) = showInBrackets (Addition x y)
                      showSubt (Subtraction x y) = showInBrackets (Subtraction x y)
                      showSubt x = show x
            show (Division x y) = showDiv x ++ " / " ++ showDiv y
                where showDiv (Addition x y) = showInBrackets (Addition x y)
                      showDiv (Subtraction x y) = showInBrackets (Subtraction x y)
                      showDiv (Multiplication x y) = showInBrackets (Multiplication x y)
                      showDiv (Division x y) = showInBrackets (Division x y)
                      showDiv x = show x
            show (Degree x y) = showDeg x ++ " ^ " ++ show y
                where showDeg (Addition x y) = showInBrackets (Addition x y)
                      showDeg (Subtraction x y) = showInBrackets (Subtraction x y)
                      showDeg (Multiplication x y) = showInBrackets (Multiplication x y)
                      showDeg (Division x y) = showInBrackets (Division x y)
                      showDeg (Degree x y) = showInBrackets (Degree x y)
                      showDeg x = show x
main = do
    let expr1 = Multiplication (Constant 5) Variable
    putStr ("(5x)' = ")
    putStrLn (show $ simplifyExpr (derivative expr1))
    let expr2 = Degree (Addition (Multiplication (Constant 3) (Degree Variable 2)) (Addition (Multiplication (Constant 6) Variable) (Constant 8))) 3
    putStr ("((3x^2 + 6x + 8)^3)' = ")
    putStrLn (show $ simplifyExpr (derivative expr2))
    let expr3 = Degree (Degree (Degree Variable 2) 5) 4
    putStr ("((x^2)^5)^4 = ")
    putStrLn (show $ simplifyExpr (derivative expr3))