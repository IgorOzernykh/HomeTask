isBracket :: Char -> Bool
isBracket b
		| b == '(' || b == ')' || b == '[' || b == ']' || b == '{' || b == '}' || b == '<' || b == '>' = True
		| otherwise = False

isPair :: Char -> Char -> Bool
isPair '(' ')' = True
isPair '[' ']' = True
isPair '{' '}' = True
isPair '<' '>' = True
isPair _ _ = False


isCorrect :: [Char] -> [Char] -> Bool
isCorrect [] [] = True
isCorrect [] _ = False
isCorrect (x:xs) [] 
				| isBracket x = isCorrect xs (x:[])
				| otherwise = isCorrect xs []
isCorrect (x:xs) stack
					| not (isBracket x) = isCorrect xs stack
					| isPair (head stack) x = isCorrect xs (tail stack)
					| otherwise = isCorrect xs (x:stack)

checkBrackets str = isCorrect str []

main = do
	putStrLn(show $ checkBrackets "if (a[2] == b) { Tree<int> *tree = new Tree<int>() }")
	putStrLn(show $ checkBrackets "std::cout << arr[0]")