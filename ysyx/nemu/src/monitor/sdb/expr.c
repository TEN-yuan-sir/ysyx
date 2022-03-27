#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>


enum {
  TK_NOTYPE = 256, TK_EQ,
  /* TODO: Add more token types */
  TK_NUM 
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"==", TK_EQ},        // equal

  {"\\-",'-'},			// minus 
  {"\\*",'*'},			//times
  {"\\/",'/'},			//frac
  {"\\(",'('},			//left block
  {"\\)",')'},			//right block
  {"[0-9]+",TK_NUM}		//NUM
 
  
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {
};


/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;


        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
	
int t = nr_token;
        switch (rules[i].token_type) {
			case TK_NOTYPE: {break;}
			case TK_NUM:{
			//Watch out! If do not memset, it will cause bugs, the last time input will be remain.
			memset(tokens[t].str,'\0',sizeof(tokens[t].str));
			tokens[t].type=rules[i].token_type;
			strncpy(tokens[t].str,substr_start,substr_len);
			printf("tokens[%d].str=%s\n",t,tokens[t].str);	
			nr_token++;
			break;
					};

		  default: {tokens[t].type=rules[i].token_type; };
			printf("tokens[%d].str=%s\n",t,tokens[t].str);	
			nr_token++;
			break;
        }
				  
		
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
 // TODO();TODO

  
  for(int i = 0; i< nr_token;i++){
	  if(tokens[i].type==TK_NUM){
		  printf("|NUM");
	  }else{
	  printf("|\"%2c\" ",tokens[i].type);
			  }
  }
  printf("|\n");

  for(int i = 0; i< nr_token;i++){
	  printf("|\"%s\"",tokens[i].str);
			  }
  printf("|\n");
 
  
  

  //eval

bool check_parentheses(int p,int q){
  if(strcmp(tokens[p].str,"(") &  strcmp(tokens[p].str,"(")){ 
	  return true;
			  }
  else
  { 
  return false;
  }
}

		 

  int eval(int p,int q){
	  int num;
	  if(p > q){
		  return 0;
	  }
	  else if (p == q){
		  return sscanf("%d",tokens[p].str,&num);
				  }
		else if ( check_parentheses(p,q)){
			
	  printf("ture");
				  	return eval(p + 1, q - 1);
				  }
			 else{
				   return 1;	
				  }
  }


  int val=eval(0,nr_token);
  printf("The value of the expr is \n");
}
