#import <ParseKit/PEGParser.h>

enum {
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_GE = 14,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_COMMA,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_OR,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_LT,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_LE,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_EQ,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_DOT,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_GT,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_OPENPAREN,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_YES,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_NO,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_CLOSEPAREN,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_NE,
    EXPRESSIONSYNTAXPARSER_TOKEN_KIND_AND,
};

@interface ExpressionSyntaxParser : PEGParser

@end
