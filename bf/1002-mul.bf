,          ; Read first digit
[-        ; Loop until first digit becomes 0
  >>>>+    ; Increment second cell and move to third cell
  <<<<<<<  ; Move back to first cell
  -        ; Decrement first digit
]
>>>>>>     ; Move to third cell
[-<+>      ; Multiply second and third cells, store result in second cell
<<<<<<     ; Move back to first cell
.          ; Print result (as an ASCII character)
