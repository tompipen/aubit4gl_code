/*
// Tables that should be created in informix engine.
// This table is not yet completed.
*/

CREATE TABLE update_table (
  firstColumn SMALLINT,
  secondColumn CHAR(10),
  thirdColumn INTEGER
);
CREATE VIEW v_update_table AS SELECT * FROM update_table;
