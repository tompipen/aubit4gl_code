code
#include "soapH.h"
#include "MantisConnectBinding.nsmap"
#define DTYPE_TEXT 12



// Settings...
#define MANTIS_ANONENTRY 	"anonentry"
#define MANTIS_PRIORITY 	"Normal"
#define MANTIS_SEVERITY 	"Crash"
#define MANTIS_STATUS 		"new"
#define MANTIS_REPRODUCIBILITY 	"N/A"
#define MANTIS_RESOLUTION 	"open"
#define MANTIS_PROJECTION 	"none"
#define MANTIS_ETA 		"none"
#define MANTIS_VIEW_STATE 	"public"
#define MANTIS_CATEGORY 	"Automatic"


int A4GL_isscrmode (void);
char * acl_getenv_not_set_as_0 (char *s);
static struct ns1__AccountData *getUserAccount(char *username) ;
struct soap soap;
static struct ns1__ObjectRef *newObjectRef (char *s) ;
static void trim_scrdump(char *s) ;
char *A4GL_get_running_program(void);
int aclfgl_fgl_getpid(int n);
int aclfgl_aclfgl_get_user(int n);
int aclfgl_aclfgl_getcwd(int n);
int aclfgl_aclfgl_text_as_str(int n);


static char *get_username(void) {
char *ptr;
ptr=acl_getenv("MANTIS_USERNAME");
if (ptr==NULL) return "mantis";
return ptr;
}

static char *get_password(void) {
char *ptr;
ptr=acl_getenv("MANTIS_PASSWORD");
if (ptr==NULL) return "mantis";
return ptr;
}

static char *get_projectid(void) {
char *ptr;
ptr=acl_getenv("MANTIS_PROJECTID");
if (ptr==NULL) return "1";
return ptr;
}

endcode


define mv_l text

function errlog(ln,mod,err,errmsg)
define ln integer
define mod char(64)
define errmsg char(1024)
define err integer
define lv_cline char(2000)
define lv_continue integer
define a integer
define lv_fname_scrdump char(300)
define lv_user char(8)
define lv_pid integer
define lv_lastkey integer
define lv_pwd char(512)
define lv_summary char(512)
define rprog char(512)
code
  if (A4GL_isscrmode ())
    A4GL_gotolinemode ();
endcode

#display "Error:", err
#display errmsg
display "An error has occurred...."
display "Please wait - Generating report for techsupport...."
code
fflush(stdout);
endcode

let lv_fname_scrdump="/tmp/scr.out.err_", fgl_getpid() using "<<<<<<"

call aclfgl_dump_screen(lv_fname_scrdump)
locate mv_l in file lv_fname_scrdump

# Lets get as much info as we can...
let lv_user=aclfgl_get_user()
let lv_pid=fgl_getpid()
code
{
A4GL_push_char(A4GL_get_running_program());
A4GL_pop_var2(&rprog,0,512);
}
endcode

let lv_lastkey=fgl_lastkey()
let lv_pwd=aclfgl_getcwd()
let lv_summary=rprog clipped," ",err using "-<<<<<<"," ",mod clipped, " Line ",ln

code
{
char *scrdump;
char *found=NULL;
//char Build[200]="";
char description[12000];
char additional[12000];
struct ns1__mc_USCOREproject_USCOREget_USCOREissuesResponse r_get_issues;


printf("."); fflush(stdout);

soap_init2(&soap, SOAP_IO_DEFAULT, SOAP_XML_TREE);

//soap_set_sent_logfile(&soap, "sent.log");



  // lets search for a matching issue...
  A4GL_trim(lv_summary);
  printf( "."); fflush(stdout);

  if (soap_call_ns1__mc_USCOREproject_USCOREget_USCOREissues(&soap, NULL,NULL, get_username(),get_password(),get_projectid(),"1","100000",&r_get_issues)) {
	// Error in soap call..
      	soap_print_fault(&soap, stderr);
	return 0;
  }

  if (r_get_issues.return_!=NULL)  {
		// We got something back - search through to find our summary...
  		for (a=0;a<r_get_issues.return_->__size;a++) {
			struct ns1__IssueData* issue;
			issue=r_get_issues.return_->__ptr[a];
			if (strcmp(issue->summary, lv_summary)==0) { // Found this error before...
				found= issue->id;
			}
  		}
  }



  if (found)  {
		char *rval;
		struct ns1__IssueNoteData note;
		struct ns1__AccountData *userAccount;
	
		A4GL_trim(lv_user);
		// Add a note to an existing issue...
		// 'found' contains our issue ID..
		userAccount=getUserAccount(lv_user);
		if (userAccount==NULL) {
			userAccount=getUserAccount(MANTIS_ANONENTRY);
		}
		note.id=NULL;
		note.reporter=userAccount;
		sprintf(additional,"Occurred for User:%s PID=%ld Lastkey:%ld CWD=%s", lv_user, lv_pid, lv_lastkey, lv_pwd);
		
		note.text=additional;
		note.view_USCOREstate=NULL;
		note.date_USCOREsubmitted=NULL;
		note.last_USCOREmodified=NULL;
		printf("#\n"); fflush(stdout);
		//A4GL_pause_execution();
		
		soap_call_ns1__mc_USCOREissue_USCOREnote_USCOREadd(&soap, NULL,NULL, get_username(),get_password(),found,&note,&rval);
		printf("\n** It would appear that TechSupport are already aware of this problem - their reference ID is %s\n",found);
		printf("** however, a note has been added to say that it has happend again\n");
		fflush(stdout);
  } else {
		xsd__integer rid;
		struct ns1__IssueData issue;
		struct ns1__AccountData *userAccount;
	
		A4GL_trim(lv_user);
		userAccount=getUserAccount(lv_user);
		if (userAccount==NULL) {
			userAccount=getUserAccount(MANTIS_ANONENTRY);
		}

		// Add as a new issue
		A4GL_push_param (&mv_l, (int) (DTYPE_TEXT + ENCODE_SIZE (sizeof (struct fgl_int_loc))));
		aclfgl_aclfgl_text_as_str(1) ;
		scrdump=A4GL_char_pop();
		trim_scrdump(scrdump);
		A4GL_trim(errmsg);
		sprintf(description,"Error Message:%s\nScreen Dump<pre>%s</pre>",errmsg,scrdump);
		A4GL_trim(lv_pwd);
		sprintf(additional,"User:%s PID=:%ld Lastkey:%ld PWD=%s ", lv_user, lv_pid, lv_lastkey, lv_pwd);

		issue.id=NULL;
		issue.last_USCOREupdated=NULL;

		issue.project=newObjectRef(get_projectid());
		issue.priority=newObjectRef(MANTIS_PRIORITY);
		issue.severity=newObjectRef(MANTIS_SEVERITY);
		issue.status=newObjectRef(MANTIS_STATUS);
		issue.reproducibility=newObjectRef(MANTIS_REPRODUCIBILITY);
		issue.resolution=newObjectRef(MANTIS_RESOLUTION);
		issue.projection=newObjectRef(MANTIS_PROJECTION);
		issue.eta=newObjectRef(MANTIS_ETA);
		issue.view_USCOREstate=newObjectRef(MANTIS_VIEW_STATE);
		issue.category=MANTIS_CATEGORY;



		issue.os_USCOREbuild=NULL;
		issue.date_USCOREsubmitted=NULL;
		issue.handler=NULL;
		issue.fixed_USCOREin_USCOREversion=NULL;
		issue.steps_USCOREto_USCOREreproduce=NULL;
		issue.attachments=NULL;
		issue.relationships=NULL;
		issue.notes=NULL;
		issue.custom_USCOREfields=NULL;
		issue.sponsorship_USCOREtotal=NULL;

		issue.summary=NULL;
		issue.description=NULL;
		issue.additional_USCOREinformation=NULL;
		issue.platform=NULL;
		issue.reporter=NULL;
		issue.version=NULL;
		issue.build=NULL;
		issue.os=NULL;
		issue.reporter=userAccount;


		issue.platform=acl_getenv_not_set_as_0("TARGET");
		issue.version=NULL;
		issue.build=NULL;
		issue.os=NULL;
		issue.summary=lv_summary;
		issue.description=description;
		issue.additional_USCOREinformation=additional;



  		if (soap_call_ns1__mc_USCOREissue_USCOREadd(&soap, NULL, NULL, get_username(),get_password(),&issue,&rid)) {
			printf("Failed to add...\n");
			fflush(stdout);
      			soap_print_fault(&soap, stderr);
			return 0;
  		} else {
			printf("#\nAdded as mantis ID : %s\n",rid); fflush(stdout);
		}
  }

}
endcode

end function


code

struct ns1__AccountData *getUserAccount(char *username) {
struct ns1__mc_USCOREproject_USCOREget_USCOREusersResponse rusers;
int a;
printf( "."); fflush(stdout);

  	// Lets search for our users name
  	// if we get a match with a Mantis user - we'll use that
  	// mantis user..
  	if (soap_call_ns1__mc_USCOREproject_USCOREget_USCOREusers(&soap, NULL,NULL,get_username(),get_password(),"ALL_PROJECTS","0", &rusers)) {
      		soap_print_fault(&soap, stderr);
      		exit(1);
	}

 	if (rusers.return_)  {
		// We got some users back - search trough the usernames to 
		// see if we match our username..
		for (a=0;a<rusers.return_->__size;a++) {
			if (strcmp(rusers.return_->__ptr[a]->name,username)==0) {
				return rusers.return_->__ptr[a];
			}
		}
 	} 
	return NULL;
}


static struct ns1__ObjectRef *newObjectRef (char *s) {
	struct ns1__ObjectRef *p;

	p=malloc(sizeof(struct ns1__ObjectRef));
	p->name=NULL;
	p->id=s;
	return p;
}

static void trim_scrdump(char *s) {
int a;
for (a=strlen(s)-1;a>=0;a--) {
	if (s[a]=='\n' || s[a]=='\r' || s[a]=='\t' || s[a]==' ') s[a]=0;
	else break;
}
}
endcode

