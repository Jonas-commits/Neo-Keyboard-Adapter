import codecs
from collections import defaultdict


leaf = '<>'
root = defaultdict(dict)


def attach(branch, trunk):
    if len(branch) == 0:
        return
    elif len(branch) == 1:
        trunk[leaf].append(branch[0])
    else:
        node = branch[0]
        others = branch[1:]
        if node not in trunk:
            trunk[node] = defaultdict(dict, ((leaf, []),))
        attach(others, trunk[node])


def dump(d, indent=0):
    for key, value in d.items():
        if key == leaf:
            if value:
                print('   ' * indent + str(value[0]))
        else:
            print('  ' * indent + str(key))
            if isinstance(value, dict):
                dump(value, indent + 1)
            else:
                print('   ' * (indent + 1) + str(value))


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
                    attach(sequence, root)


if __name__ == '__main__':
    parse('base.module')
    dump(root)
