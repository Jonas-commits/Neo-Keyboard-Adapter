import codecs
from collections import defaultdict

LEAF = '<>'
PREFIX_ID = 'NODE_'
V_UNI = 'const uint16_t Compose::'
V_IDENT = 'const Node Compose::'
VH_IDENT = 'const static Node'
GEN_MAGIC = '<GENERATOR>'

ROOT = defaultdict(dict, ((LEAF, []),))
values = []

NEO_MAP = {
    'a': 'L1, KEY_D',
    'b': 'L1, KEY_N',
    'c': 'L1, KEY_R',
    'd': 'L1, KEY_SEMICOLON',
    'e': 'L1, KEY_F',
    'f': 'L1, KEY_O',
    'g': 'L1, KEY_I',
    'h': 'L1, KEY_U',
    'i': 'L1, KEY_S',
    'j': 'L1, KEY_SLASH',
    'k': 'L1, KEY_Y',
    'l': 'L1, KEY_E',
    'm': 'L1, KEY_M',
    'n': 'L1, KEY_J',
    'o': 'L1, KEY_G',
    'p': 'L1, KEY_V',
    'q': 'L1, KEY_P',
    'r': 'L1, KEY_K',
    's': 'L1, KEY_H',
    't': 'L1, KEY_L',
    'u': 'L1, KEY_A',
    'v': 'L1, KEY_W',
    'w': 'L1, KEY_T',
    'x': 'L1, KEY_Q',
    'y': 'L1, KEY_QUOTE',
    'z': 'L1, KEY_B',
    'adiaeresis' : 'L1, KEY_C',
    'odiaeresis' : 'L1, KEY_X',
    'udiaeresis' : 'L1, KEY_Z',
    'A': 'L2, KEY_D',
    'B': 'L2, KEY_N',
    'C': 'L2, KEY_R',
    'D': 'L2, KEY_SEMICOLON',
    'E': 'L2, KEY_F',
    'F': 'L2, KEY_O',
    'G': 'L2, KEY_I',
    'H': 'L2, KEY_U',
    'I': 'L2, KEY_S',
    'J': 'L2, KEY_SLASH',
    'K': 'L2, KEY_Y',
    'L': 'L2, KEY_E',
    'M': 'L2, KEY_M',
    'N': 'L2, KEY_J',
    'O': 'L2, KEY_G',
    'P': 'L2, KEY_V',
    'Q': 'L2, KEY_P',
    'R': 'L2, KEY_K',
    'S': 'L2, KEY_H',
    'T': 'L2, KEY_L',
    'U': 'L2, KEY_A',
    'V': 'L2, KEY_W',
    'W': 'L2, KEY_T',
    'X': 'L2, KEY_Q',
    'Y': 'L2, KEY_QUOTE',
    'Z': 'L2, KEY_B',
    'Adiaeresis': 'L2, KEY_C',
    'Odiaeresis': 'L2, KEY_X',
    'Udiaeresis': 'L2, KEY_Z',
    '1': 'L1, KEY_1',
    '2': 'L1, KEY_2',
    '3': 'L1, KEY_3',
    '4': 'L1, KEY_4',
    '5': 'L1, KEY_5',
    '6': 'L1, KEY_6',
    '7': 'L1, KEY_7',
    '8': 'L1, KEY_8',
    '9': 'L1, KEY_9',
    '0': 'L1, KEY_0',
    'Tab': 'L1, KEY_TAB',
    'KP_1': 'L1, KEY_1',
    'KP_2': 'L1, KEY_2',
    'KP_3': 'L1, KEY_3',
    'KP_4': 'L1, KEY_4',
    'KP_5': 'L1, KEY_5',
    'KP_6': 'L1, KEY_6',
    'KP_7': 'L1, KEY_7',
    'KP_8': 'L1, KEY_8',
    'KP_9': 'L1, KEY_9',
    'KP_0': 'L1, KEY_0',
    'KP_Divide': 'L3, KEY_S',
    'Multi_key': 'L3, KEY_TAB',
    'Multi_Key': 'L3, KEY_TAB',
    'dead_grave': 'L1, KEY_EQUAL',
    'dead_cedilla': 'L2, KEY_EQUAL',
    'dead_ogonek': 'L2, KEY_EQUAL',
    'dead_abovering': 'L3, KEY_EQUAL',
    'dead_diaeresis': 'L4, KEY_EQUAL',
    'dead_dasia': 'L5, KEY_EQUAL',
    'dead_macron': 'L6, KEY_EQUAL',
    'dead_acute': 'L1, KEY_RIGHT_BRACE',
    'dead_tilde': 'L2, KEY_RIGHT_BRACE',
    'dead_stroke': 'L3, KEY_RIGHT_BRACE',
    'dead_doubleacute': 'L4, KEY_RIGHT_BRACE',
    'dead_psili': 'L5, KEY_RIGHT_BRACE',
    'dead_hook': 'L5, KEY_RIGHT_BRACE',
    'dead_breve': 'L6, KEY_RIGHT_BRACE',
    'dead_circumflex': 'L1, KEY_TILDE',
    'dead_caron': 'L2, KEY_TILDE',
    'U21BB': 'L3, KEY_TILDE',
    'dead_abovedot': 'L4, KEY_TILDE',
    'dead_horn': 'L5, KEY_TILDE',
    'U02DE': 'L5, KEY_TILDE',
    'dead_belowdot': 'L6, KEY_TILDE',
    'nobreakspace': 'L5, KEY_SPACE',
    'space': 'L1, KEY_SPACE',
    'ellipsis': 'L3, KEY_Q',
    'underscore': 'L3, KEY_W',
    'underbar': 'L3, KEY_W',
    'rightsinglequotemark': 'L3, KEY_0',
    'comma': 'L1, KEY_COMMA',
    'period': 'L1, KEY_PERIOD',
    'exclam': 'L3, KEY_Y',
    'question': 'L3, KEY_H',
    'exclamdown': 'L4, KEY_Y',
    'questiondown': 'L4, KEY_H',
    'minus': 'L1, KEY_MINUS',
    'colon': 'L3, KEY_SEMICOLON',
    'slash': 'L3, KEY_S',
    'backslash': 'L3, KEY_A',
    'less': 'L3, KEY_U',
    'greater': 'L3, KEY_I',
    'bracketleft': 'L3, KEY_E',
    'bracketright': 'L3, KEY_R',
    'parenleft': 'L3, KEY_J',
    'parenright': 'L3, KEY_K',
    'bar': 'L3, KEY_C',
    'sterling': 'L4, KEY_6',
    'malesymbol': 'L5, KEY_4',
    'femalesymbol': 'L5, KEY_5',
    'U26A5': 'L5, KEY_6',
    'Greek_DELTA': 'L6, KEY_SEMICOLON',
    'dagger': 'L2, KEYPAD_9',
    'U25A1': 'L6, KEYPAD_0',
    'U2714': 'L2, KEYPAD_7',
    'U2718': 'L2, KEYPAD_8',
    'U2423': 'L2, KEYPAD_0',
    'U017F': 'L3, KEY_LEFT_BRACE',
    'U21CC': 'L3, KEYPAD_3',
    'enfilledcircbullet': 'L2, KEY_PERIOD',
    'asciicircum': 'L3, KEY_T',
    'asciitilde': 'L3, KEY_V',
    'Greek_lambda': 'L5, KEY_E',
    'Greek_alpha': 'L5, KEY_D',
    'Greek_omega': 'L5, KEY_T',
    'Greek_OMEGA': 'L6, KEY_T',
    'Greek_gamma': 'L5, KEY_I',
    'Greek_GAMMA': 'L5, KEY_I',
    'Greek_iota': 'L5, KEY_S',
    'Greek_upsilon': 'L5, KEY_QUOTE',
    'Greek_epsilon': 'L5, KEY_F',
    'Greek_phi': 'L5, KEY_P',
    'Greek_tau': 'L5, KEY_L',
    'Greek_omicron': 'L5, KEY_G',
    'Greek_pi': 'L5, KEY_V',
    'Greek_PI': 'L6, KEY_V',
    'Greek_beta': 'L5, KEY_N',
    'logicalor': 'L6, KEY_2',
    'logicaland': 'L6, KEY_3',
    'equal': 'L3, KEY_O',
    'apostrophe': 'L3, KEY_PERIOD',
    'multiply': 'L3, KEY_G',
    'plus': 'L3, KEY_N',
    'KP_Add': 'L3, KEY_N',
    'KP_Subtract': 'L1, KEY_MINUS',
    'radical': 'L6, KEY_W',
    'integral': 'L6, KEY_S',
    'degree': 'L2, KEY_1',
    'braceleft': 'L3, KEY_D',
    'braceright': 'L3, KEY_F',
    'KP_Equal': 'L3, KEY_O',
    'plusminus': 'L3, KEYPAD_ADD',
    'elementof': 'L6, KEY_G',
    'union': 'L6, KEY_Z',
    'intersection': 'L6, KEY_X',
    'Greek_SIGMA': 'L6, KEY_H',
    'ampersand': 'L3, KEY_P',
    'rightarrow': 'L3, KEYPAD_6',
    'leftarrow': 'L3, KEYPAD_4',
    'uparrow': 'L3, KEYPAD_8',
    'downarrow': 'L3, KEYPAD_2',
    'includein': 'L6, KEY_A',
    'Greek_delta': 'L5, KEY_SEMICOLON',
    'Greek_theta': 'L5, KEY_SLASH',
    'Greek_rho': 'L5, KEY_K',
    'Greek_chi': 'L5, KEY_R',
    'Greek_eta': 'L5, KEY_C',
    'approxeq': 'L5, KEY_NUM_LOCK',
    'emdash': 'L1, KEY_MINUS',
    'endash': 'L1, KEY_MINUS',
    'includedin' : 'L6, KEY_A',
    'numbersign' : 'L3, KEY_Z',
    'asterisk' : 'L3, KEY_G',
}


class Uint16_Exception(Exception):
    pass


class Char_Exception(Exception):
    pass


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
        fh.write('\t' + VH_IDENT + ' ' + p + '[] PROGMEM;' + '\n')

    i = dictlen
    for key, value in d.items():
        if i == 1:
            last = '1'
        else:
            last = '0'

        if key != LEAF:
            if len(value) == 1:
                fc.write('\t{{' + last + ', 1, ' + str(key) + '}, {' + str(value[LEAF][0]) + '}},\n')
            else:
                fc.write('\t{{' + last + ', 0, ' + str(key) + '}, {(uint16_t) ' + PREFIX_ID + str(id(value)) + '}},\n')
        i -= 1

    if dictlen > 1:
        fc.write('};\n\n')

    for value in d.values():
        if isinstance(value, dict):
            dump_c(value, fc, fh)


def parse(filename):
    with codecs.open(filename, encoding='utf-8', mode='r') as f:
        for x in f:
            sequence = []
            x = str(x)
            x = x.replace(' ', '')  # remove whitespace
            x = x.replace('\t', '')
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
                        if (ord(uc) > 0xffff):
                            raise Uint16_Exception(uc)
                        sequence.append(hex(ord(uc)))
                        attach(sequence, ROOT)
                    else:
                        raise Char_Exception(uc)

            except KeyError:
                print('WARNING: no mapping found for \'' + str(s) + '\' - skipped containing sequence')
            except Uint16_Exception as e:
                print('WARNING: Unicode \'' + str(e) + '\' out of supported 2-Byte-Range - skipped containing sequence')
            except Char_Exception as e:
                print('WARNING: Strings not supported. Skipped \"' + str(e) + '\"')


def inject_template(f_template, f_gen, f_out):
    f_out.write('/***********************************************************************/\n')
    f_out.write('/******************* This file is generated by *************************/\n')
    f_out.write('/******************* the Compose Generator *****************************/\n')
    f_out.write('/***********************************************************************/\n\n')
    for x in f_template:
        if GEN_MAGIC in x:
            f_out.writelines(f_gen)
        else:
            f_out.write(x)


def main():
    # use modules from neo compose/src
    print('===base.module===')
    parse('base.module')

    print('===dead_keys.module===')
    parse('dead_keys.module')

    print('===dead_greek.module===')
    parse('dead_greek.module')

    print('===misc.module===')
    parse('misc.module')

    print('\n\n===lang.module===')
    parse('lang.module')

    print('\n\n===math.module===')
    parse('math.module')
    with open('compose.gen.cpp', 'w') as f_gen_c:
        with open('compose.gen.h', 'w') as f_gen_h:
            dump_c(ROOT, f_gen_c, f_gen_h)

    with open('compose.gen.cpp', 'r') as f_gen_c:
        with open('Compose.template.cpp', 'r') as f_tmp_c:
            with open('../keyboard/Compose.gen.cpp', 'w') as f_out_c:
                inject_template(f_tmp_c, f_gen_c, f_out_c)

    with open('compose.gen.h', 'r') as f_gen_h:
        with open('Compose.template.h', 'r') as f_tmp_h:
            with open('../keyboard/Compose.gen.h', 'w') as f_out_h:
                inject_template(f_tmp_h, f_gen_h, f_out_h)


if __name__ == '__main__':
    main()
