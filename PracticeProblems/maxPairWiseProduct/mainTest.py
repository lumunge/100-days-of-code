import random
import sys
import os

#Accept the number of tests as a commend line parameter
tests = int(sys.argv[1])
#Accept the parameter for the tests as a command line parameter
n = int(sys.argv[2])
n1 = int(sys.argv[3])


for i in range(tests):
    print("Test #" + str(i))
    #Run the generator testGen.py with parameter n and the seed i
    os.system("python3 testGenerator.py " + str(n) + " " + str(n1) + " > input.txt")
    #Run model solution maxPairProduct1.py
    os.system("python3 maxPairWiseProductModelFast.py < input.txt > maxPairProductMainRes.txt")
    #Run main solution
    os.system("python3 maxPairWiseProductModel.py < input.txt > maxPairProductModelRes.txt")

    #Read the output of main solution
    with open("maxPairProductMainRes.txt") as f: maxPairWiseProductModelFast = f.read()
    print("maxPairWiseProductModelFast.py: ", maxPairWiseProductModelFast)
    #Read output of model solution
    with open("maxPairProductModelRes.txt") as f: maxPairWiseProductModel = f.read()
    print("maxPairWiseProductModel.py: ", maxPairWiseProductModel)
    if(maxPairWiseProductModelFast != maxPairWiseProductModel):
        break






