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
            for s in symbols:
                s = s.replace('<', '')
                sequence.append(s)
            if len(sequence) > 0:
                uc = suffix.split('\"')[1]
                if len(uc) == 1:
                    sequence.append(hex(ord(uc)))
                    attach(sequence, ROOT)


def main():
    parse('base.module')
    with open('compose.c.gen', 'w') as fc:
        with open('compose.h.gen', 'w') as fh:
            dump_c(ROOT, fc, fh)
            dump_values(fc)


if __name__ == '__main__':
    main()
