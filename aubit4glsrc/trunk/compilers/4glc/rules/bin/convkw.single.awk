/^#/ {next}
/FKEY/ {next}
/SINGLE_KEY/ {next}
/CONTROL_KEY/ {next}
(NF>=1) {
kw= $1
if (def[kw]) next
def[kw]=1
if (length($2)>1) {
if (NF<=2) { print kw > "generated/single_words" }
}
}

