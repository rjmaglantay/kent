/* sageExp.h was originally generated by the autoSql program, which also 
 * generated sageExp.c and sageExp.sql.  This header links the database and
 * the RAM representation of objects. */

#ifndef SAGEEXP_H
#define SAGEEXP_H

struct sageExp
/* data related to sage Experiments, tissued descriptions, etc. */
    {
    struct sageExp *next;  /* Next in singly linked list. */
    int num;	/* Index of the experiment in the sage table. */
    char *exp;	/* experiments name. */
    int totalCount;	/* Sum of all the tag counts for this experiment. */
    char *tissueType;	/* Brief Description of cells used. */
    char *tissueDesc;	/* Brief Description of tissues. */
    char *tissueSupplier;	/* Who supplied the tissue. */
    char *organism;	/* organism source of cells. */
    char *organ;	/* organ identifier. */
    char *producer;	/* source of tissue. */
    char *desription;	/* description of experiment. */
    };

void sageExpStaticLoad(char **row, struct sageExp *ret);
/* Load a row from sageExp table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct sageExp *sageExpLoad(char **row);
/* Load a sageExp from row fetched with select * from sageExp
 * from database.  Dispose of this with sageExpFree(). */

struct sageExp *sageExpLoadAll(char *fileName);
/* Load all sageExp from a tab-separated file.
 * Dispose of this with sageExpFreeList(). */

struct sageExp *sageExpCommaIn(char **pS, struct sageExp *ret);
/* Create a sageExp out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new sageExp */

void sageExpFree(struct sageExp **pEl);
/* Free a single dynamically allocated sageExp such as created
 * with sageExpLoad(). */

void sageExpFreeList(struct sageExp **pList);
/* Free a list of dynamically allocated sageExp's */

void sageExpOutput(struct sageExp *el, FILE *f, char sep, char lastSep);
/* Print out sageExp.  Separate fields with sep. Follow last field with lastSep. */

#define sageExpTabOut(el,f) sageExpOutput(el,f,'\t','\n');
/* Print out sageExp as a line in a tab-separated file. */

#define sageExpCommaOut(el,f) sageExpOutput(el,f,',',',');
/* Print out sageExp as a comma separated list including final comma. */

#endif /* SAGEEXP_H */

