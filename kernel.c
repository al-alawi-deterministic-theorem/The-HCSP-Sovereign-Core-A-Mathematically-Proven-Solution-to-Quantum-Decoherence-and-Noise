%%writefile kernel.c
typedef struct {
    int R; 
    int N;
} State;

/*@ 
  @ requires current.R >= 0 && current.R <= 20000000; 
  @ requires i >= 0 && i < 1000; 
  @ ensures \result.R >= 0;
  @ assigns \nothing;
*/
State transition_function(State current, int i) {
    State next;
    
    // تقسيم المعادلة لمساعدة المحرك على الاستيعاب
    int numerator = current.R * 105;
    int denominator = 100 + (i * 2);
    
    /*@ assert numerator >= 0; */
    /*@ assert denominator >= 100; */
    
    next.R = numerator / denominator; 
    next.N = i;
    return next;
}

/*@
  @ assigns \nothing;
  @ ensures \result == 0 || \result == 1;
*/
int verify_liveness(State s) {
    return (s.R > 0) ? 1 : 0; 
}
