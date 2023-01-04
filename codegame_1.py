line_1 = input()
line_2 = input()
line_3 = input()

result = ""

if ((len(line_1) == len(line_2)) and (len(line_1) == len(line_3))):
    if ((len(line_1) % 3) == 0):
        
        i = 0
        while i <= int((len(line_1)) - 1):
            
            if (line_1[i] == " ") and (line_1[i + 1] == "_") and (line_1[i + 2] == " "): #Soit 0 2 3 5 6 7 8 9
                
                if (line_2[i] == "|") and (line_2[i + 1] == "_") and (line_2[i + 2] == "|"): #Soit 8 9
                    if (line_3[i] == "|") and (line_3[i + 1] == "_") and (line_3[i + 2] == "|"):
                        result += str(8)
                    elif (line_3[i] == " ") and (line_3[i + 1] == "_") and (line_3[i + 2] == "|"):
                        result += str(9)
                elif (line_2[i] == " ") and (line_2[i + 1] == "_") and (line_2[i + 2] == "|"): #Soit 2 3

                    if (line_3[i] == "|") and (line_3[i + 1] == "_") and (line_3[i + 2] == " "):
                        result += str(2)
                    elif (line_3[i] == " ") and (line_3[i + 1] == "_") and (line_3[i + 2] == "|"):
                        result += str(3)
                
                elif (line_2[i] == "|") and (line_2[i + 1] == "_") and (line_2[i + 2] == " "): #Soit 5 6

                    if (line_3[i] == " ") and (line_3[i + 1] == "_") and (line_3[i + 2] == "|"):
                        result += str(5)
                    elif (line_3[i] == "|") and (line_3[i + 1] == "_") and (line_3[i + 2] == "|"):
                        result += str(6)                

                elif (line_2[i] == "|") and (line_2[i + 1] == " ") and (line_2[i + 2] == "|"): # Soit 0
                    if (line_3[i] == "|") and (line_3[i + 1] == "_") and (line_3[i + 2] == "|"):
                        result += str(0)
                        
                elif (line_2[i] == " ") and (line_2[i + 1] == " ") and (line_2[i + 2] == "|"): # Soit 7
                    if (line_3[i] == " ") and (line_3[i + 1] == " ") and (line_3[i + 2] == "|"):
                        result += str(7)


            elif (line_1[i] == " ") and (line_1[i + 1] == " ") and (line_1[i + 2] == " "): #Soit 1 4
                if (line_2[i] == " ") and (line_2[i + 1] == " ") and (line_2[i + 2] == "|"):
                    if (line_3[i] == " ") and (line_3[i + 1] == " ") and (line_3[i + 2] == "|"):
                        result += str(1)


                elif (line_2[i] == "|") and (line_2[i + 1] == "_") and (line_2[i + 2] == "|"):
                    if (line_3[i] == " ") and (line_3[i + 1] == " ") and (line_3[i + 2] == "|"):
                        result += str(4)
            i += 3
print(result)
