DB DOCUMENTER
=============

Introduction
------------

The database documenter is a tool that has been implemented all over the
times in severall tecnologies.

This one, is all builded in Java and it shows the information in JSP, or 
generate it in static html files.

Credits
-------

The tool was created by Moredata (http://www.moredata.pt), and it is now part
of aubit4gl.

USE CASE(s)
-----------

  - Navigator
  - Table Model
  - Process Model
  - Model Editor
  - Factory(s) / Importer(s):
    - Database
    - XML
    - CSV
  - Builder(s) / Exporter(s):
    - Database
    - XML
    - CSV
  - Validator
  - Repository Handler:
    - Create
    - Drop
    - Delete
  - GUI Interface
  - CUI Interface

DIAGRAM(s)
----------
  - Use Case
  - Data Model

CURRENT GOALS / USE CASE(s) BEING IMPLEMENTED
---------------------------------------------
  - Repository handler
  - GUI Infrastructure
  - CUI Infrastructure

TODO
----

  - Infrastructure:
     - Implement and use log4j
     - Use getopt
     - Create an executor in CUI mode
     - Start with a manager in GUI mode
     - Usage of other databases such as hsql (to be embeded in a jar).
  - Model:
     - See the diferences to the perl version
  - Repository:
     - Implement and test
  - Factory:
     - Load from the database 