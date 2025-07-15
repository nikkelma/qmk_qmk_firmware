# `kracerlink` GMMK PRO ANSI keymap

This layout inherits many of the features/design of the default keymap:
- FN is a momentary toggle to layer 1
- FN + backslash maps to the RESET key
- Fn + N toggles NKRO

A few swaps have been made on the base layer to accommodate for my
preferences as a software engineer to have home and end alongside of delete.

Delete is between F12 and the encoder knob, while the right system
key column from top to bottom is Home / End / PgUp / PgDn.

I swapped to this keyboard from a WASD Code keyboard, so I've gained muscle
memory of using my thumb on FN and right fingers to control media playback:
- Fn + Home -> Play
- Fn + End  -> Next
- Fn + PgUp -> Prev

## Build commands / details - DigitalOcean

On Builder VM:
```bash
mkdir -p github.com/nikkelma
cd github.com/nikkelma

sudo apt-get install python3.12-venv -y

git clone https://github.com/nikkelma/qmk_qmk_firmware.git
cd qmk_qmk_firmware
git remote add upstream https://github.com/qmk/qmk_firmware.git

python3 -m venv .venv
source .venv/bin/activate

python -m pip install qmk

qmk setup

qmk config user.keyboard=gmmk/pro/rev1/ansi
qmk config user.keymap=kracerlink

qmk compile
```

On local Mac:
```bash
scp qmk-builder:'~'/github.com/nikkelma/qmk_qmk_firmware/gmmk_pro_rev1_ansi_nikkelma.bin ~/files/github/nikkelma/qmk_qmk_firmware/.build/gmmk_pro_rev1_ansi_nikkelma.bin
```
