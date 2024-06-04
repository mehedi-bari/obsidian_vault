		Triggers:
		- A trigger is a stored program that is invoked automatically in response to an event
		- The events are: INSERT, DELETE, and UPDATE.
		- Trigger are run BEFORE, or AFTER the SQL query is executed.
		- To show a trigger: SHOW TRIGGERS;
		- To drop a trigger; DROP TRIGGER trigger_name;
			- CREATE TRIGGER trigger_name
			- BEFORE | AFTER
			- INSERT | UPDATE | DELETE
			- ON table_name
			- BEGIN trigger_body END

		Before vs After:
		- Before triggers are useful to update or validate record values before they're saved to the database.
		- You an prevent the update if validations fail.
		- Then send SIGNAL SQLSTATE '4500'
		- After triggers are used to access field values that are set by the system (such as a lastmodifieddate field)
		- After triggers are useful in auditing.





![[Screenshot 2022-11-17 at 22.08.55.png]]


![[Screenshot 2022-11-17 at 22.14.09.png]]

![[Screenshot 2022-11-17 at 22.24.03.png]]


![[Screenshot 2022-11-17 at 22.25.10.png]] 

		BEFORE AFTER DELETE:
		- The DELETE trigger doesn't have access to the NEW modifier.
		- BEFORE is useful to check that the delete is valid.
		- AFTER is usueful for auditing, as you can copy the deleted record into an archieve table with the user_id that deleted it.


		Multiple Triggers:
		- You can call multiple triggers by using the KEYWORDS FOLLOWs or PRECEDS.
		- FOLLOWS allows the new trigger to activate after an existing trigger.
		- PRECEDES allows the new triiger to activate before an existing trigger.
		- However this approach can get really confusing, so it easier to get the trigger to call a procedure.
		- You can include the CALL procedure_name.

