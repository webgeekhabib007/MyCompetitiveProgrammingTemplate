import sys
import datetime, time


Problem_name = sys.argv[1]
date = datetime.date.today()
Solver = "Codecrasader036"
site = "codeforces"


with open("./main.cpp", "r") as file:
    prev = f"//Problem Name : {Problem_name}\n//Solver : {Solver}\n//Date : {date}\n\n\n"
    cat = file.read()
    cat = prev+ cat
    with open(f"{site}/{Problem_name}.cpp","w") as output:
        output.write(cat)

        output.close()

    file.close()
    
