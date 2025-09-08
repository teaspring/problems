import re
import unittest

def getBondNum(bond: str) -> int:
    # get m of "(m)"
    if len(bond.strip()) != 3: return 0
    return int(bond.strip()[1]) 

def checkCarbonAround(allLines: [], carbon: str, carbonRow: int, carbonCol: int) -> bool:
    # check all the bonds around given carbon
    carLine = allLines[carbonRow]
    # get n of "CHn"
    carbonRides = int(carbon[2])

    upBoundM = rightBoundM = downBoundM = leftBoundM = 0
    # up bound
    if (carbonRow > 0 and len(allLines[carbonRow - 1]) >= carbonCol + 3):
        upBoundM = getBondNum(allLines[carbonRow-1][carbonCol : carbonCol+3])
    # right bound
    if (carbonCol + 6 <= len(carLine)):
        rightBoundM = getBondNum(carLine[carbonCol+3 : carbonCol+6])
    # down bound
    if (carbonRow < len(allLines)-1 and len(allLines[carbonRow + 1]) >= carbonCol + 3):
        downBoundM = getBondNum(allLines[carbonRow+1][carbonCol : carbonCol+3])
    # left bound
    if (carbonCol - 3 >= 0):
        leftBoundM = getBondNum(carLine[carbonCol-3 : carbonCol])
    # sum up
    return carbonRides + upBoundM + rightBoundM + downBoundM + leftBoundM == 4

def check_compounds_valid(lines: list[str]) -> bool:
    carbonPat = re.compile(r'(CH[0-4])')
    for i in range(len(lines)):
        line = lines[i]
        beginIdx = 0
        while (mat := carbonPat.search(line, pos=beginIdx)):
            carbonBeginIdx, carbon = mat.start(), mat.group()
            if not checkCarbonAround(lines, carbon, i, carbonBeginIdx):
                return False
            beginIdx = carbonBeginIdx + len(mat.group())
    return True

class TestOrganicCompoundsCheck(unittest.TestCase):
    # each test case must start with 'test_'
    def test_valid(self):
        org_compounds = [
            "CH2(1)CH2(1)CH1(1)CH2",
            "(1)         (1)   (1)",
            "CH2         CH2   CH2",
            "(1)         (1)   (1)",
            "CH2(1)CH2(1)CH1(1)CH2"
        ]
        self.assertTrue(check_compounds_valid(org_compounds))

    def test_invalid(self):
        org_compounds = [
            "CH3(1)CH1(1)CH2(1)CH1(1)CH3",
            "(1)         (1)",
            "CH3         CH1(1)CH1(1)CH3",
            "            (1)",
            "            CH3"
        ]
        self.assertFalse(check_compounds_valid(org_compounds))

if __name__ == '__main__':
    unittest.main()