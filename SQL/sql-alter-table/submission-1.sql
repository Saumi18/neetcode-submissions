CREATE TABLE books (
  id INTEGER,
  title TEXT,
  author TEXT
);
-- Do not modify above this line --

ALTER TABLE books ADD published_year INTEGER;
ALTER TABLE books DROP author;
ALTER TABLE books RENAME id TO isbn;










-- Do not modify below this line --
SELECT column_name, data_type, column_default
FROM information_schema.columns
WHERE table_name = 'books'
ORDER BY column_name;
