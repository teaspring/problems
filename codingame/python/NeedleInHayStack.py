import unittest

def create_set(needle: str) -> set:
    ''' possibly to be: "a-c, 1-2, a, d"
    '''
    st = set()
    parts = [x.strip() for x in needle.split(',')]
    for part in parts:
        if '-' in part:
            begin, end = part.split('-') # both inclusive
            for i in range(0, ord(end) - ord(begin) + 1):
                st.add(chr(ord(begin) + i))
        else:
            st.add(part.lower())
    return st

def find_needle_in_haystack(hay_stack: str, needle: str) -> str:
    ''' entry point
    '''
    st = create_set(needle)
    mp = {}
    min_win_size, min_win_b = len(hay_stack), 0
    # iterate in window
    b, e = 0, 0
    while e < len(hay_stack):
        # move e to widen window
        while e < len(hay_stack):
            x = hay_stack[e]
            if x in st:
                if x not in mp:
                    mp[x] = 1
                else:
                    mp[x] += 1
            if len(mp.keys()) == len(st): break
            e += 1
        # move b to narrow window
        while len(mp.keys()) == len(st):
            x = hay_stack[b]
            if x in mp:
                if mp[x] == 1:  break
                mp[x] -= 1
            b += 1
        # new window is ready
        win_size = e - b + 1
        if win_size < min_win_size:
            min_win_b, min_win_size = b, win_size
        if e >= len(hay_stack) - 1: break # window cannot move any more
        # update window
        del mp[hay_stack[b]]
        b += 1
        e += 1
    return f"{min_win_b} {min_win_b + min_win_size - 1}"

class TestNeedleInHayStack(unittest.TestCase):
    ''' unit test
    '''
    def test_simple_haystack(self):
        hay_stack = "aaaaddaaabbbbbc"
        self.assertEqual('8 14', find_needle_in_haystack(hay_stack, 'a-c'))
        self.assertEqual('8 14', find_needle_in_haystack(hay_stack, 'c,a,b'))
        self.assertEqual('5 14', find_needle_in_haystack(hay_stack, 'd, b-c, a'))
        self.assertEqual('3 4', find_needle_in_haystack(hay_stack, 'd,a'))

    def test_long_haystack(self):
        stacks = [
            "andthecircleiscustomarilysubdividedinto360degreesalthoughpiradiansyieldshalfthecircleendsometimesreferredtoasarchimedessconstantbecausethegreekmathematiciancomputedlowerandupperboundsofpibydrawingregu",
            "larpolygonsinsideandoutsideacircleingermanyitwascalledtheludolphiannumberuntiltheearly20thcenturyafterthedutchmathematicianludolphvanceulen15401610whocalculatedupto35digitsofpiinthelate16thcenturymart",
            "inrennersep072016asofthebeginningof2019morethan22trilliondecimaldigitsofpiareknownseethewikipediaarticlechronologyofcomputationofpiharveypdalejan232019onmarch142019emmaharukaiwaoannouncedthecalculatio",
            "nof314trilliondigitsofpiusinggooglecloudsinfrastructuredavidradcliffeapr102019alsovolumeofthreequartersofasphereofradius1omarepolaug162019onaugust52021researchersfromtheuniversityofappliedsciencesofth",
            "egrisonsinswitzerlandannouncedtheyhadcalculated628trilliondigitsguinnessworldrecordshasnotverifiedthisyetalonsodelarteaug232021thehermitelindemann1882theoremstatesthatifzisanonzeroalgebraicnumberthene",
            "zisatranscendentnumberthetranscendenceofpithenresultsfromeulersrelationeipi1peterluschnyjul212023referencesmohammadkazarianasummaryofmathematicalworksofghiyathuddinjamshidkashanijournalofrecreationalm",
            "athematicsvol291pp32421998jarndtchaenelpiunleashedspringerny2001pbeckmannahistoryofpigolempressboulderco1977jpdelahayelefascinantnombrepipourlascienceparis1997peyardandjplafonthenumberpiamermathsoc200",
            "4srfinchmathematicalconstantsencyclopediaofmathematicsanditsapplicationsvol94cambridgeuniversitypresssection14lepetitarchimedespecialissueonpisupplementtono645may1980adcsamienscliffordapickoverapassio",
            "nformathematicswiley2005seep31njasloaneahandbookofintegersequencesacademicpress1973includesthissequencenjasloaneandsimonplouffetheencyclopediaofintegersequencesacademicpress1995includesthissequencelin",
            "ksharryjsmithtableofnanforn120000sanjarmabrarovrehansiddiquirajinderkjagpalandbrendanmquineunconditionalapplicabilityofthelehmersmeasuretothetwotermmachinlikeformulaforpiarxiv200411711mathgm2020davean"
        ]
        hay_stack = ''.join(stacks)
        self.assertEqual("695 734", find_needle_in_haystack(hay_stack, "1,6,2,t,h,o-u"))
        self.assertEqual("1260 1308", find_needle_in_haystack(hay_stack, "a-n,o,p,y,9,2"))
        self.assertEqual("1916 1974", find_needle_in_haystack(hay_stack, "c,i,l,y,t,u-x"))

if __name__ == '__main__':
    unittest.main()