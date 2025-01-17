/* $NetBSD: fmt_block.c,v 1.7 2023/05/22 23:03:16 rillig Exp $ */

/*
 * Tests for formatting blocks of statements and declarations.
 *
 * See also:
 *	lsym_lbrace.c
 *	psym_stmt.c
 *	psym_stmt_list.c
 */

//indent input
void
function(void)
{
	if (true) {

	}

	{
		print("block");
	}
}
//indent end

/*
 * Before 2023-05-11, indent incorrectly merged the '} {' into a single line,
 * even though they are completely unrelated.
 */
//indent run-equals-input


/*
 * Two adjacent blocks must not be merged.  They are typically used in C90 and
 * earlier to declare local variables with a limited scope.
 */
//indent input
void
function(void)
{
	{}{}
}
//indent end

//indent run
void
function(void)
{
	{
	}
	{
	}
}
//indent end

//indent run-equals-prev-output -bl
