import unittest

def hacking_pair_encode(msg1: str, msg2: str, msg3: str) -> str:
    res = []
    # hex string to int each of which repsents a byte
    for i in range(0, len(msg1), 2):
        b1 = int(msg1[i:i+2], 16)
        b2 = int(msg2[i:i+2], 16)
        b3 = int(msg3[i:i+2], 16)
        b = b1 ^ b2 ^ b3
        res.append(chr(b))
    return ''.join(res)

class TestHackingRobberCity(unittest.TestCase):
    # each test case must start with 'test_'
    #
    def test_simple_short(self):
        msg1 = "391813c092a2d5ac9acb705dfe41be3df08de67d1145cbcc3f"
        msg2 = "03adeae2c8c2f2336c8a8d312733c2456e76e0b2d9068adc3f"
        msg3 = "72d0954e354045f09461dc4c911d0b58ff8963efb12c34303f"
        expected = "Hello bob ! How are you ?"
        # assert
        self.assertEqual(expected, hacking_pair_encode(msg1, msg2, msg3))

    def test_long_inner_bytes(self):
        msg1 = "2f03f64ddb650a4517b689a75c1d149dc38a43f0cf4f332871c1144e185552ccab3b13f6f0e831022f7963f5cf59224f4af60bde421be2be107146967d9c6c86b7ec16f81df38febb0810add94abd31e1e056042de83c790eb4102ed7ffd2419d75b1a90ea84f0af46ea9ae2a3e2b9ec6f0d1b99a0f5200e8f0d7d902f13b96aa50c1a1fc03fe245cc835756b03436396230"
        msg2 = "67c7034ed1cb194b6c4db54783d0ac512dfb21ebeaf87e0c4db88bacd4e9c3627e8ff5c2d462d5bef2f90417586d7aa2d77248fdb37239042905b3ce197a629e013e693d25d7d8a6de673aa244bd1263ac93a7998267770fb0366a05c186e2d50be5f04d190211c0d1982f45cf890063d2f326e8d37edb8dc6fabc87fba324259d91610ddae0ff7162991e0e603436396230"
        msg3 = "0a90a22f2ada7c2e08925190b3a4deb5ce1e176905d13850490bfac2a9c4f2c6b4da815157a6c4d0b8f44091b7412b88bdc50670d11eb2ce5154982144d73e2a82ff1dac4c04273f0790510bb536aa18cbb6f2bf3ed788fb6e14588e8f4da3afec8b8eb996e3d758f24681915d5cd8bf84ca584717efcbe171c4f671b185f9290aa9497729ba7c0c9d282c6be03436396230"
        expected = "BTW, to simplify our future exchanges, let's use AES with my 1024-bit private key 5db38d5c0f16ec05ddee67e44617a094e6dd0b837fe5df242e3ea832e30469b0"
        # assert
        self.assertEqual(expected, hacking_pair_encode(msg1, msg2, msg3))

if __name__ == "__main__":
    unittest.main()