-- MySQL dump 10.13  Distrib 8.0.38, for Win64 (x86_64)
--
-- Host: localhost    Database: hobu
-- ------------------------------------------------------
-- Server version	8.0.39

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `hobune`
--

DROP TABLE IF EXISTS `hobune`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `hobune` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Nimi` varchar(255) NOT NULL,
  `Omanik_id` bigint unsigned NOT NULL,
  `Tall_id` bigint unsigned NOT NULL,
  `Treeningprogramm` bigint unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `hobune_treeningprogramm_foreign` (`Treeningprogramm`),
  KEY `hobune_omanik_id_foreign` (`Omanik_id`),
  KEY `hobune_tall_id_foreign` (`Tall_id`),
  CONSTRAINT `hobune_omanik_id_foreign` FOREIGN KEY (`Omanik_id`) REFERENCES `omanik` (`id`),
  CONSTRAINT `hobune_tall_id_foreign` FOREIGN KEY (`Tall_id`) REFERENCES `tall` (`id`),
  CONSTRAINT `hobune_treeningprogramm_foreign` FOREIGN KEY (`Treeningprogramm`) REFERENCES `treeningprogramm` (`idTreeningprogramm`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hobune`
--

LOCK TABLES `hobune` WRITE;
/*!40000 ALTER TABLE `hobune` DISABLE KEYS */;
INSERT INTO `hobune` VALUES (2,'Rosin',1,1,1);
/*!40000 ALTER TABLE `hobune` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `omanik`
--

DROP TABLE IF EXISTS `omanik`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `omanik` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Nimi` varchar(255) NOT NULL,
  `Aadress` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `omanik`
--

LOCK TABLES `omanik` WRITE;
/*!40000 ALTER TABLE `omanik` DISABLE KEYS */;
INSERT INTO `omanik` VALUES (1,'Kaisa','Seene');
/*!40000 ALTER TABLE `omanik` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tall`
--

DROP TABLE IF EXISTS `tall`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tall` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Nimi` varchar(255) NOT NULL,
  `Aadress` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tall`
--

LOCK TABLES `tall` WRITE;
/*!40000 ALTER TABLE `tall` DISABLE KEYS */;
INSERT INTO `tall` VALUES (1,'Nurga tall','Seene1');
/*!40000 ALTER TABLE `tall` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `treening`
--

DROP TABLE IF EXISTS `treening`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `treening` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Kirjeldus` bigint unsigned NOT NULL,
  `Kuupäev` date NOT NULL,
  `Hobuseid` bigint unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `treening_hobuseid_foreign` (`Hobuseid`),
  CONSTRAINT `treening_hobuseid_foreign` FOREIGN KEY (`Hobuseid`) REFERENCES `hobune` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `treening`
--

LOCK TABLES `treening` WRITE;
/*!40000 ALTER TABLE `treening` DISABLE KEYS */;
INSERT INTO `treening` VALUES (4,55,'2024-10-01',2);
/*!40000 ALTER TABLE `treening` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `treeningprogramm`
--

DROP TABLE IF EXISTS `treeningprogramm`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `treeningprogramm` (
  `idTreeningprogramm` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Nimi` varchar(255) NOT NULL,
  `Kirjeldus` varchar(255) NOT NULL,
  PRIMARY KEY (`idTreeningprogramm`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `treeningprogramm`
--

LOCK TABLES `treeningprogramm` WRITE;
/*!40000 ALTER TABLE `treeningprogramm` DISABLE KEYS */;
INSERT INTO `treeningprogramm` VALUES (1,'Rosin','Galopp');
/*!40000 ALTER TABLE `treeningprogramm` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ülevaatus`
--

DROP TABLE IF EXISTS `ülevaatus`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ülevaatus` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Vaktsineerimine` varchar(255) DEFAULT NULL,
  `Kirjeldus` varchar(255) NOT NULL,
  `Kuupäev` date NOT NULL,
  `Hobuneid` bigint unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `Ülevaatus_hobuneid_foreign` (`Hobuneid`),
  CONSTRAINT `Ülevaatus_hobuneid_foreign` FOREIGN KEY (`Hobuneid`) REFERENCES `hobune` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ülevaatus`
--

LOCK TABLES `ülevaatus` WRITE;
/*!40000 ALTER TABLE `ülevaatus` DISABLE KEYS */;
INSERT INTO `ülevaatus` VALUES (1,NULL,'Kasutusel haavasprei','2024-06-09',2);
/*!40000 ALTER TABLE `ülevaatus` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-10-03  9:33:44
