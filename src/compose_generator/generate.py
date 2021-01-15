import codecs
from collections import defaultdict

LEAF = '<>'
PREFIX_ID = 'OBJ_'
NAME_UNI = 'composeSymbols'
V_UNI = 'const uint16_t Compose::'
V_IDENT = 'const Node Compose::'
VH_IDENT = 'const static Node'

ROOT = defaultdict(dict, ((LEAF, []),))
values = []

NEO_MAP = {
    'a': '{L1, KEY_U}',
    'b': '{L1, KEY_Y}',
    'c': '{L1, KEY_QUOTE}',
    'd': '{L1, KEY_A}',
    'e': '{L1, KEY_L}',
    'f': '{L1, KEY_E}',
    'g': '{L1, KEY_O}',
    'h': '{L1, KEY_S}',
    'i': '{L1, KEY_G}',
    'j': '{L1, KEY_N}',
    'k': '{L1, KEY_R}',
    'l': '{L1, KEY_T}',
    'm': '{L1, KEY_M}',
    'n': '{L1, KEY_B}',
    'o': '{L1, KEY_F}',
    'p': '{L1, KEY_Q}',
    'q': '{L1, KEY_X}',
    'r': '{L1, KEY_C}',
    's': '{L1, KEY_I}',
    't': '{L1, KEY_W}',
    'u': '{L1, KEY_H}',
    'v': '{L1, KEY_P}',
    'w': '{L1, KEY_V}',
    'x': '{L1, KEY_SEMICOLON}',
    'y': '{L1, KEY_K}',
    'z': '{L1, KEY_LEFT_BRACE}',
    'A': '{L2, KEY_U}',
    'B': '{L2, KEY_Y}',
    'C': '{L2, KEY_QUOTE}',
    'D': '{L2, KEY_A}',
    'E': '{L2, KEY_L}',
    'F': '{L2, KEY_E}',
    'G': '{L2, KEY_O}',
    'H': '{L2, KEY_S}',
    'I': '{L2, KEY_G}',
    'J': '{L2, KEY_N}',
    'K': '{L2, KEY_R}',
    'L': '{L2, KEY_T}',
    'M': '{L2, KEY_M}',
    'N': '{L2, KEY_B}',
    'O': '{L2, KEY_F}',
    'P': '{L2, KEY_Q}',
    'Q': '{L2, KEY_X}',
    'R': '{L2, KEY_C}',
    'S': '{L2, KEY_I}',
    'T': '{L2, KEY_W}',
    'U': '{L2, KEY_H}',
    'V': '{L2, KEY_P}',
    'W': '{L2, KEY_V}',
    'X': '{L2, KEY_SEMICOLON}',
    'Y': '{L2, KEY_K}',
    'Z': '{L2, KEY_LEFT_BRACE}',
    '1': '{L1, KEY_1}',
    '2': '{L1, KEY_2}',
    '3': '{L1, KEY_3}',
    '4': '{L1, KEY_4}',
    '5': '{L1, KEY_5}',
    '6': '{L1, KEY_6}',
    '7': '{L1, KEY_7}',
    '8': '{L1, KEY_8}',
    '9': '{L1, KEY_9}',
    '0': '{L1, KEY_0}',
    'Tab': '{L1, Key_Tab}',
    'KP_1': '{L1, KEYPAD_1}',
    'KP_2': '{L1, KEYPAD_2}',
    'KP_3': '{L1, KEYPAD_3}',
    'KP_4': '{L1, KEYPAD_4}',
    'KP_5': '{L1, KEYPAD_5}',
    'KP_6': '{L1, KEYPAD_6}',
    'KP_7': '{L1, KEYPAD_7}',
    'KP_8': '{L1, KEYPAD_8}',
    'KP_9': '{L1, KEYPAD_9}',
    'KP_0': '{L1, KEYPAD_0}',
    'KP_Divide': '{L1, KEYPAD_DIVIDE}',
    'Multi_key': '{L3, KEY_TAB}',
    'dead_grave': '{L1, KEY_EQUAL}',
    'dead_cedilla': '{L2, KEY_EQUAL}',
    'dead_abovering': '{L3, KEY_EQUAL}',
    'dead_diaeresis': '{L4, KEY_EQUAL}',
    'dead_dasia': '{L5, KEY_EQUAL}',
    'dead_macron': '{L6, KEY_EQUAL}',
    'dead_acute': '{L1, KEY_RIGHT_BRACE}',
    'dead_tilde': '{L2, KEY_RIGHT_BRACE}',
    'dead_stroke': '{L3, KEY_RIGHT_BRACE}',
    'dead_doubleacute': '{L4, KEY_RIGHT_BRACE}',
    'dead_psili': '{L5, KEY_RIGHT_BRACE}',
    'dead_breve': '{L6, KEY_RIGHT_BRACE}',
    'dead_circumflex': '{L1, KEY_TILDE}',
    'dead_caron': '{L2, KEY_TILDE}',
    'U21BB': '{L3, KEY_TILDE}',
    'dead_abovedot': '{L4, KEY_TILDE}',
    'U02DE': '{L5, KEY_TILDE}',
    'dead_belowdot': '{L6, KEY_TILDE}',
    'nobreakspace': '{L5, KEY_SPACE}',
    'space': '{L1, KEY_SPACE}',
    'ellipsis': '{L3, KEY_Q}',
    'underscore': '{L3, KEY_W}',
    'rightsinglequotemark': '{L3, KEY_0}',
    'comma': '{L1, KEY_COMMA}',
    'period': '{L1, KEY_PERIOD}',
    'exclam': '{L3, KEY_Y}',
    'question': '{L3, KEY_H}',
    'exclamdown': '{L4, KEY_Y}',
    'questiondown': '{L4, KEY_H}',
    'minus': '{L1, KEY_MINUS}',
    'colon': '{L3, KEY_SEMICOLON}',
    'slash': '{L3, KEY_S}',
    'backslash': '{L3, KEY_A}',
    'less': '{L3, KEY_U}',
    'bracketleft': '{L3, KEY_E}',
    'bracketright': '{L3, KEY_R}',
    'parenleft': '{L3, KEY_J}',
    'parenright': '{L3, KEY_K}',
    'bar': '{L3, KEY_C}',
    'sterling': '{L4, KEY_6}',
    'malesymbol': '{L5, KEY_4}',
    'femalesymbol': '{L5, KEY_5}',
    'U26A5': '{L5, KEY_6}',
    'Greek_DELTA': '{L6, KEY_SEMICOLON}',
    'dagger': '{L2, KEYPAD_9}',
    'U25A1': '{L6, KEYPAD_0}',
    'U2714': '{L2, KEYPAD_7}',
    'U2718': '{L2, KEYPAD_8}',
    'U2423': '{L2, KEYPAD_0}',
    'U017F': '{L3, KEY_LEFT_BRACE}',
    'U21CC': '{L3, KEYPAD_3}',
    'enfilledcircbullet': '{L2, KEY_PERIOD}',
}


def attach(branch, trunk):
    if len(branch) == 0:
        return
    elif len(branch) == 1:
        trunk[LEAF].append(branch[0])
    else:
        node = branch[0]
        others = branch[1:]
        if node not in trunk:
            trunk[node] = defaultdict(dict, ((LEAF, []),))
        attach(others, trunk[node])


def dump_c(d, fc, fh):
    dictlen = len(d)
    if d == ROOT:
        p = 'root'
    else:
        p = PREFIX_ID + str(id(d))

    if dictlen > 1:
        fc.write(V_IDENT + p + '[] PROGMEM = {\n')
        fh.write(VH_IDENT + ' ' + p + '[] PROGMEM;' + '\n')

    if dictlen > 2:
        fc.write('\t{{' + str((dictlen) % 256) + ', ' + str((dictlen) // 256) + '}, nullptr},\n')

    for key, value in d.items():
        if key != LEAF:
            if len(value) == 1:
                val = value[LEAF][0]
                if val not in values:
                    values.append(val)
                    pos = len(values) - 1
                else:
                    pos = values.index(val)

                fc.write('\t{' + str(key) + ', ' + NAME_UNI + ' + ' + str(pos) + '},\n')
            else:
                fc.write('\t{' + str(key) + ', ' + PREFIX_ID + str(id(value)) + '},\n')

    if dictlen > 1:
        fc.write('};\n\n')

    for value in d.values():
        if isinstance(value, dict):
            dump_c(value, fc, fh)


def dump_values(f):
    f.write(V_UNI + NAME_UNI + '[] PROGMEM = {\n')
    i = 0
    for x in values:
        i += 1
        f.write('\t' + str(x) + ',')
        if i % 8 == 0:
            f.write('\n')
    f.write('\n};\n')


def parse(filename):
    with codecs.open(filename, encoding='utf-8', mode='r') as f:
        for x in f:
            sequence = []
            x = str(x)
            x = x.replace(' ', '')  # remove whitespace
            x = str(x.split('#')[0])  # remove comments
            symbols = x.split('>')
            suffix = symbols.pop()  # get all the unicode and other garbage

            try:
                for s in symbols:
                    s = s.replace('<', '')
                    sequence.append(NEO_MAP[s])

                if len(sequence) > 0:
                    uc = suffix.split('\"')[1]
                    if len(uc) == 1:
                        sequence.append(hex(ord(uc)))
                        attach(sequence, ROOT)

            except KeyError:
                print('WARNING: no mapping found for \'' + str(s) + '\' - skipped containing sequence')


def main():
    parse('base.module')
    with open('compose.c.gen', 'w') as fc:
        with open('compose.h.gen', 'w') as fh:
            dump_c(ROOT, fc, fh)
            dump_values(fc)


if __name__ == '__main__':
    main()
