#!/bin/sh
#!/bin/bash

sed -i "" "s/third-32/third-64/g" `grep 'third-32' -rl ./src`
