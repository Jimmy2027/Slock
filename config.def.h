/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
/* Background image path, should be available to the user above */
static const char* background_image = "/home/hendrik/.local/share/slock";
static const char* background_image_list = "/home/hendrik/src/slockbg/slock_bg_list.txt";
