{

Original article, by Claus Samuelsen (csa AT dk DOT ibm DOT com) :

http://www-106.ibm.com/developerworks/db2/library/techarticle/dm-0501samuelsen/


MQI consists of CALLS through which applications can access the MQ manager, 
and STRUCTURES that applications use for passing messages to and from the 
queue manager. The most basic CALLS are:

    * MQCONN and MQDISC for connecting and disconnecting to a MQ Manager
    * MQOPEN and MQCLOSE for opening and closing a queue
    * MQPUT and MQGET for writing and reading messages

MQI contains also the following CALLS, but these are not used in this article:

    * MQINQ to retrieve attributes for a queue
    * MQSET to set or change a queue's attributes
    * MQBEGIN, MQCMT, and MQBACK to manage transactional handling through the MQ manager

Communicating with the MQ server takes the following five steps, in this order:

   1. Connect to the MQ manager
   2. Open a queue
   3. Write or read messages on the queue
   4. Close the queue
   5. Disconnect from the MQ manager
   
}

MAIN

DEFINE 
	connect_handle, queue_handle
		INT,
	msg,queue_name
		CHAR(80)

	LET queue_name = "queueManager"
		
		
#Connecting to the MQ Manager

	LET connect_handle = fgl_mqconnect(queue_name)
	IF fgl_mqstatus() <> 0 THEN
	  	CALL error_handling()
	END IF
	
#Opening the queue
	

	LET queue_handle = fgl_mqopen4write(connect_handle)
	IF fgl_mqstatus() <> 0 THEN
	  	CALL error_handling()
	END IF
	
#Writing to the queue

	DECLARE cust_curs FOR select fname || ' ' || lname from customer

	FOREACH cust_curs INTO msg
	  	CALL fgl_mqwrite(connect_handle, queue_handle, msg, LENGTH(msg))
		IF fgl_mqstatus() <> 0 THEN
	      	CALL error_handling()
		END IF
    END FOREACH
	
	
#Closing the queue. Not stricly needed as disconnect closes all queues opened
#on this connection, but a good practice

	CALL fgl_mqclose(connect_handle, queue_handle)

#Disconnecting from the MQ Manager
	
	CALL fgl_mqdisconnect(connect_handle)
	
END MAIN

FUNCTION error_handling()

#Error handling goes here...

END FUNCTION

