CREATE TABLE `Course`(
    `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `Kirjeldus` VARCHAR(255) NOT NULL
);
CREATE TABLE `Student`(
    `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `Eesnimi` VARCHAR(255) NOT NULL,
    `Perekonnanimi` VARCHAR(255) NOT NULL,
    `Sünnikuupäev` DATE NULL
);
CREATE TABLE `Comments`(
    `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `Õpilase nimi` VARCHAR(255) NOT NULL,
    `Kommentaar` VARCHAR(255) NOT NULL,
    `Kuupäev` DATE NOT NULL
);
CREATE TABLE `Group`(
    `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `Õpetajaid` BIGINT NOT NULL,
    `Name` VARCHAR(255) NOT NULL
);
CREATE TABLE `Teacher`(
    `id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    `Eesnimi` VARCHAR(255) NOT NULL,
    `Perekonnanimi` VARCHAR(255) NOT NULL,
    `Sünnikuupäev` DATE NULL
);
ALTER TABLE
    `Student` ADD CONSTRAINT `student_id_foreign` FOREIGN KEY(`id`) REFERENCES `Comments`(`id`);
ALTER TABLE
    `Teacher` ADD CONSTRAINT `teacher_eesnimi_foreign` FOREIGN KEY(`Eesnimi`) REFERENCES `Group`(`id`);
ALTER TABLE
    `Teacher` ADD CONSTRAINT `teacher_id_foreign` FOREIGN KEY(`id`) REFERENCES `Course`(`id`);
ALTER TABLE
    `Student` ADD CONSTRAINT `student_eesnimi_foreign` FOREIGN KEY(`Eesnimi`) REFERENCES `Group`(`id`);