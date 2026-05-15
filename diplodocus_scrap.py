import os
import time
import random
import json
import requests
from selenium import webdriver
from collections import Counter
import matplotlib.pyplot as plt
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from webdriver_manager.chrome import ChromeDriverManager  # pyright: ignore[reportMissingImports]

PATH_TO_DOWNLOAD = "C:\\Users\\mathi\\OneDrive\\Bureau\\test diplodocus scrapping"

# INCOMPLET!
BASE_URL = {
    "Série 1 - Légation de France à Mexico" : {
        "Correspondance" : {

            "Mission Alexandre Martin": {
                "432PO/1/1": {
                    "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/twj39zg6mfvr/4fe169de-93d1-4056-af6b-a7bbde6112c4",
                    "page_num": 99,
                    "date": "1825-1828"
                },
                "432PO/1/2": {
                    "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/sv512wzl4dh8/9895f626-4e26-4969-9a27-f16a1cf0e5a7",
                    "page_num": 196,
                    "date": "1827"
                },
                "432PO/1/3": {
                    "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/d574h302qc69/ee3ee7af-d171-4824-a08e-38e5dd3e3ca5",
                    "page_num": 245,
                    "date": "1828-1829",
                    "note": "Seule la correspondance politique porte l'ancienne cote [7]. Les dossiers portant les cotes [9] et [11] n'ont pas été retrouvés."
                },
                "432PO/1/4": {
                    "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/nhxf04v2g1jl/3053bcb5-2c34-4f03-b261-a052f33dbf26",
                    "page_num": 258,
                    "date": "1826-1828"
                }
            },
            "Correspondance avec le ministère des affaires étrangères": {
                "Direction politique": {
                    "Correspondance à l'arrivée": {
                        "432PO/1/5": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/wfjgtpmk029d/426b6576-d490-4196-97d8-32d6eba43dee",
                            "page_num": 208,
                            "date": "1829-1833"
                        }, 
                        "432PO/1/6": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/rw94cxmv3f8s/ed98c711-dc84-4a79-8133-7834dbdb9875",
                            "page_num": 181,
                            "date": "1834-1838"
                        }, 
                        "432PO/1/7": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/xfpmc1t32sdl/f7d2dd5b-4b3b-4ae2-aae2-f1c24b6bc3dc",
                            "page_num": 190,
                            "date": "1848-1851"
                        },
                        "432PO/1/8": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/d3bkhwrsn1ft/1cb14b7b-2278-43d4-ac0b-0c1a03824510",
                            "page_num": 304,
                            "date": "1852-1855"
                        },
                        "432PO/1/9": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/k8dbsm37lhjn/26af38ee-a3c4-4080-a119-a3b1d5a6ad28",
                            "page_num": 226,
                            "date": "1856-1858"
                        },
                        "432PO/1/10": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/0vlg9j726frx/b26c2043-78aa-4be5-a36a-e6f0d09349cd",
                            "page_num": 256,
                            "date": "1859-1860, 1864-1866, 1872-1874"
                        },
                    }, 
                    "Correspondance au départ": {
                        "432PO/1/11": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/t852zpvwb10x/299e6aa2-cdfe-4a61-a9ae-a7fef7f753ee",
                            "page_num": 243,
                            "date": "1829"
                        },
                        "432PO/1/12": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/mtp924z6sbcr/4041a4e9-e28b-4625-8953-aaf43e708394",
                            "page_num": 161,
                            "date": "1831-1832"
                        },
                        "432PO/1/13": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/t9dkz82pvr47/9bf2b04e-1b63-4eb8-90f4-bb8cb8288682",
                            "page_num": 348,
                            "date": "1833-1835"
                        },
                        "432PO/1/20": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/mwk8g1n39l02/b22db7eb-491d-464a-b2a4-4ba941a30af3",
                            "page_num": 343,
                            "date": "1859-1866"
                        },
                    }
                },
                "Direction commerciale": {
                    "Correspondance à l'arrivée": {
                        "432PO/1/21": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/g8k76vtl1h3f/237838c4-1387-46f3-88a9-eb1a73a00234",
                            "page_num": 223,
                            "date": "1828-1835"
                        },
                        "432PO/1/22": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/kjsn645gt0b7/e295f636-e3f0-4ab3-baa7-3de92133490a",
                            "page_num": 188,
                            "date": "1836-1844"
                        },
                        "432PO/1/23": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/87lm4b6pzvr5/ad83f2d1-8c74-44d6-a2be-2fc5525c4e3e",
                            "page_num": 153,
                            "date": "1845-1850"
                        },
                        "432PO/1/24": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/z7slkp2x8c9w/1926911c-640c-4223-a7c7-7430fad78811",
                            "page_num": 186,
                            "date": "1851-1855"
                        },
                        "432PO/1/25": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/d4910hn3zgx5/edbcc246-1960-4dc8-b543-39b9a62f67b7",
                            "page_num": 135,
                            "date": "1856-1860"
                        },
                        "432PO/1/26": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/k5wnv28f6r9c/8abc22c9-6db9-4c4d-b8ca-a4fb48cdf25c",
                            "page_num": 256,
                            "date": "1861-1865"
                        },
                        "432PO/1/27": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/z0xbvs8j4pc3/34582621-b700-47bb-91ff-9debdfba7014",
                            "page_num": 142,
                            "date": "1866-1880"
                        },
                    },
                    "Correspondance au départ": {
                        "432PO/1/28": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/2nbc9glw6hqp/1e23f44a-bd0a-4ae1-8060-0e184674f379",
                            "page_num": 96,
                            "date": "1829"
                        },
                        "432PO/1/29": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/l6w7q5c43vz8/089685aa-848b-4691-8e3d-e104f51df31f",
                            "page_num": 170,
                            "date": "1830"
                        },
                        "432PO/1/30": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/x1plgmdsr2h4/70b5b501-ea60-4c90-b0d4-dee156136ec8",
                            "page_num": 131,
                            "date": "1831"
                        },
                        "432PO/1/31": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/02rbw69l7j5h/c67c4ed9-2592-4362-a24f-0eb1f1ed24f8",
                            "page_num": 252,
                            "date": "1832-1836"
                        },
                    }
                },
                "Direction des Archives et de la Chancellerie": {
                    "Correspondance à l'arrivée": {
                        "432PO/1/36": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/jwsx975ktg2l/7d18bdbf-f98d-438d-914b-2f9a5c655597",
                            "page_num": 163,
                            "date": "1829-1832"
                        },
                        "432PO/1/37": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/s62nxbhfwjv5/b4dda35f-4544-4151-a8a3-90d3029b952b",
                            "page_num": 294,
                            "date": "1833-1835"
                        },
                        "432PO/1/38": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/mnr1t7dbvlgz/b66c72c0-6abc-4a83-ab2a-7589161cd597",
                            "page_num": 253,
                            "date": "1836-1840"
                        },
                        "432PO/1/39": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/1h7nvk0g9jqb/05ee1925-651c-4319-9468-3525d1d561e6",
                            "page_num": 184,
                            "date": "1841-1854"
                        },
                        "432PO/1/40": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/9wpx8hbr4s72/6c474b11-0eca-45c2-84f9-1889142f9bb5",
                            "page_num": 217,
                            "date": "1856-1858"
                        },
                        "432PO/1/41": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/q0rzhxlgcnbm/d4430a1a-229b-40ef-ad1d-37a091ec2b44",
                            "page_num": 180,
                            "date": "1859-1860"
                        },
                        "432PO/1/42": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/j4lvz2brnpwg/9a694e4f-a335-4113-b7f0-cea6e5843e6a",
                            "page_num": 332,
                            "date": "1861-1864"
                        },
                        "432PO/1/43": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/vzhxp6n2lm18/03b6aca3-aa13-4955-b744-f234979a62c6",
                            "page_num": 324,
                            "date": "1865-1866"
                        },
                        "432PO/1/44": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/jxbw5m6d8pf4/800348f1-d8ba-4ee1-a205-33f539c922fa",
                            "page_num": 322,
                            "date": "1867-1868"
                        },
                        "432PO/1/45": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/jq7m963l251b/0ad68d5b-b656-44a3-92b1-355f7c51f47b",
                            "page_num": 324,
                            "date": "1869-1871"
                        },
                        "432PO/1/46": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/z4h10w9fvxrd/879dc8e4-bf78-4245-80d4-bc73a1c7eade",
                            "page_num": 267,
                            "date": "1872-1873"
                        },
                        "432PO/1/47": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/tfmr7x4kqlc6/7aabb399-a749-47f0-bfcb-0b2f3ae11c8d",
                            "page_num": 211,
                            "date": "1874-1876"
                        },
                        "432PO/1/48": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/km1nv4jdq657/0f112d07-dd12-4aa8-8862-fde17463f61f",
                            "page_num": 241,
                            "date": "1877-1880"
                        },
                    }
                },
                "Direction de la Comptabilité": {
                    "Correspondance à l'arrivée": {
                        "432PO/1/52": {
                            "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/l094dczkpwht/94a625af-b56e-41d8-9b20-f7c28d1fdcc1",
                            "page_num": 288,
                            "date": "1834-1879"
                        },
                    }
                }
            },
            "Correspondance avec le ministère de la Marine et des Colonies": {
                "Circulaires, instructions et lettres du ministère de la Marine": {
                    "432PO/1/56": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/xdhmksq291cl/a70d23f1-ddeb-473f-9e71-75b57221b514",
                        "page_num": 264,
                        "date": "1864-1866"
                    },
                },
                "Correspondance avec la flotte française (stations et divisions navales, commandants des bâtiments) au Mexique": {
                    "432PO/1/57": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/4pf3vw01djln/56fa4356-79f1-4b38-885a-7b79eba8b85a",
                        "page_num": 432,
                        "date": "1853-1857"
                    },
                    "432PO/1/58": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/q4ftc07jn3mz/5c0ea0e7-622a-472f-8524-47e2672f18eb",
                        "page_num": 350,
                        "date": "1858-1860"
                    },
                }
            },
            "Correspondance avec les postes diplomatiques et consulaires": {
                "Correspondance avec les postes consulaires français au Mexique": {
                    "432PO/1/65": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/984jkd6xhbz2/a04263eb-2c84-459b-8d34-1c4ef5ebfd79",
                        "page_num": 180,
                        "date": "1849-1867",
                        "ville": "Acapulco"
                    },
                    "432PO/1/66": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/kbzpl139w08v/2966c606-f7fe-4514-b827-160469de5b0e",
                        "page_num": 238,
                        "date": "1832-1840",
                        "ville": "Campèche"
                    },
                    "432PO/1/67": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/jbgvp3wdtr1m/f0836fc0-46e8-4298-9492-147b477b2dff",
                        "page_num": 344,
                        "date": "1841-1843",
                        "ville": "Campèche"
                    },
                    "432PO/1/103": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/nz0rqx3l71m8/14648da2-4bd0-4dd5-962e-fbdeb466da8e",
                        "page_num": 544,
                        "date": "1830",
                        "ville": "Vera Cruz"
                    },
                    "432PO/1/105": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/qlwzfd3mvgn0/7780441a-73ec-40cf-ae8b-ad7c9e08dc6c",
                        "page_num": 239,
                        "date": "1833",
                        "ville": "Vera Cruz"
                    },
                },
                "Correspondance avec les postes diplomatiques et consulaires français hors Mexique": {
                    "432PO/1/131": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/pbl3cwh91zqd/f4f1cdb8-3b1f-4a3d-9a07-29246319705e",
                        "page_num": 368,
                        "date": "1850-1878",
                        "ville": "San Francisco"
                    },
                }
            }, 
            "Correspondance avec les autorités mexicaines": {
                "Correspondance avec le gouvernement mexicain": {
                    "432PO/1/138": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/4j0c5bt7rf1k/7ee79afb-d1bb-45ab-a0ea-b928593719d4",
                        "page_num": 332,
                        "date": "1829-1830"
                    },
                    "432PO/1/139": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/2fdm1p7rs30h/fc078a60-cd30-4802-a4cf-18ddd8fe8645",
                        "page_num": 215,
                        "date": "1831-1832"
                    },
                    "432PO/1/140": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/vdkhmltjzcw7/5679c3f7-8179-4c73-90bf-b5203f9c2e0a",
                        "page_num": 222,
                        "date": "1833-1837"
                    },
                    "432PO/1/141": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/dwgf6p1lmcbs/8959095b-ffe4-43ae-8880-c4345bfce220",
                        "page_num": 189,
                        "date": "1838"
                    },
                    "432PO/1/142": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/cvxtrjd41zkm/be071912-b4a5-415a-9df2-8a44f37a0e75",
                        "page_num": 158,
                        "date": "1839-1842"
                    },
                    "432PO/1/143": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/92rdtk1w7pq4/8c51de03-d417-4e17-bbf2-393c299ef566",
                        "page_num": 355,
                        "date": "1841-1866"
                    },
                },
                "Transcription de la correspondance avec les autorités mexicaines, principalement le ministre des Relations extérieures": {
                    "432PO/1/144": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/d3blsq5tj84f/4a3b94fb-efa7-449d-a086-4cdc06d1362e",
                        "page_num": 105,
                        "date": "1848-1850"
                    },
                    "432PO/1/145": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/3lwxn840vsm9/10752c86-3285-4968-ab22-2ba27768987d",
                        "page_num": 38,
                        "date": "1857-1864"
                    },
                    "432PO/1/146": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/vm54rk760lgd/12ae1bca-473c-4f99-ac98-0eab74e0a271",
                        "page_num": 90,
                        "date": "1834-1865",
                        "note": "Correspondance avec des autorités religieuses. - Provisorat métropolitain de Mexico (1834-1836). - Archevêque de Mexico (1857, 1859, 1863). - Prélats mexicains : copie de lettres de protestation contre les Lois de Réforme (1863). Correspondance entre autorités mexicaines. - Lettres de Bénito Juarez adressées à ses lieutenants à Campèche, Merida, Oaxaca et San Cristobal (1863). - Correspondance « interceptée à Cholula » du colonel en chef de la troisième brigade d'Oaxaca avec le gouvernement (1863). - Triplicata d'une lettre du général Antonio Lopez de Santa Anna (1865)"
                    },
                }
            }, 
            "Correspondance avec les particuliers": {
                "432PO/1/147": {
                    "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/skg139vchlmb/6d124c99-eb19-41ad-a0a0-38c4352bece7",
                    "page_num": 400,
                    "date": "1827-1834",
                },
                "432PO/1/148": {
                    "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/c5g4rjkt6bwx/b667b660-94d6-4013-a449-49614c1125ca",
                    "page_num": 272,
                    "date": "1835-1836",
                },
                "432PO/1/149": {
                    "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/dtv1zk5x40mj/3c7b08eb-21b0-420d-8212-065562a826c0",
                    "page_num": 286,
                    "date": "1837-1838",
                },
                "432PO/1/150": {
                    "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/x058w9vpmrzk/67dc96ff-15ef-41ad-a983-f031c79baa14",
                    "page_num": 263,
                    "date": "1839-1840",
                },
                "432PO/1/151": {
                    "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/4h1rxsp7j0q2/ed909526-82f0-4f51-b9cb-4d292a7883ec",
                    "page_num": 466,
                    "date": "1841-1848",
                },
                "432PO/1/152": {
                    "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/12c5prq68tbm/08978dcf-af0c-4dd7-99bf-7b05adf7a5c5",
                    "page_num": 385,
                    "date": "1849-1862",
                },
                "432PO/1/153": {
                    "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/3trdh79g6pj1/e091a02f-2006-46ca-9843-872c709d62bd",
                    "page_num": 400,
                    "date": "1863-1864",
                },
                "432PO/1/154": {
                    "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/gks1ln240h6c/4821d594-0e87-4e21-b263-ee3f1dfdfd10",
                    "page_num": 428,
                    "date": "1865-1877",
                },
            },
            "Correspondance générale": {
                "Transcription de la correspondance générale au départ du poste": {
                    "432PO/1/155": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/3crd8m1wx7s9/8dfe551e-3165-4a60-b727-191ecc16b187",
                        "page_num": 104,
                        "date": "1849-1855",
                    },
                    "432PO/1/156": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/jgm5q172x3tl/1c8e63da-1e95-4aa3-b5d7-e6d64317521f",
                        "page_num": 96,
                        "date": "1855-1869",
                    },
                    "432PO/1/157": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/mcv1bjsn698h/87eb3aef-baf8-46e3-9bcb-c32d2db43752",
                        "page_num": 221,
                        "date": "1852-1855",
                    },
                }, 
                "Enregistrement de la correspondance générale de la chancellerie": {
                    "432PO/1/158": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/v96j5z3x70df/cf4331a0-fd30-40a4-bf82-1b192da84a04",
                        "page_num": 245,
                        "date": "1848-1855",
                    },
                    "432PO/1/159": {
                        "url": "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/glrvk0cmt1h6/093fdd54-21a2-43a6-a0e2-c375814322dc",
                        "page_num": 127,
                        "date": "1856-1881",
                    },
                }
            }
        },

        # VOIR PLUS TARD POUR LA SUITE.
        # https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/6mk0wvh9t4zb
        "Affaires politiques" : {},

        "Chancellerie consulaire" : {}

    },


    # Série B - Légation de France à Mexico

    # 1880-1957 - Série C
}
#BASE_URL = "https://archivesdiplomatiques.diplomatie.gouv.fr/ark:/14366/twj39zg6mfvr/4fe169de-93d1-4056-af6b-a7bbde6112c4"
#NB_PAGES = 1

DOWNLOAD = True 
PLOT_HISTO_DATES = False

if DOWNLOAD:
    # ── Activer les logs réseau (équivalent onglet Network des DevTools) ──
    chrome_options = Options()
    chrome_options.set_capability("goog:loggingPrefs", {"performance": "ALL"})

    driver = webdriver.Chrome(
        service=Service(ChromeDriverManager().install()),
        options=chrome_options,
    )
    wait = WebDriverWait(driver, 10)


def extraire_urls_images_plein_format() -> list[str]:
    """
    Parcourt les logs réseau et retourne les URLs d'images JPEG
    qui ne contiennent pas 'thumbnail' dans leur chemin.
    """
    urls = []
    for entry in driver.get_log("performance"):
        message = json.loads(entry["message"])["message"]

        # On ne s'intéresse qu'aux réponses réseau reçues
        if message.get("method") != "Network.responseReceived":
            continue

        response = message["params"]["response"]
        url = response.get("url", "")
        mime = response.get("mimeType", "")

        if "image" in mime and "thumbnail" not in url:
            urls.append(url)

    return urls


def telecharger_image(img_url: str, chemin: str) -> None:
    """
    Télécharge une image en réutilisant les cookies et le User-Agent
    de la session Selenium courante (contourne la protection de session).
    Le contournement de la protection de session revient à passer par 
    "Inspecter la page", aller dans l'onglet "Sources" puis dans l'arborescence
    chercher le dossier images et regarder les éléments qu'il contient.
    """
    cookies = {c["name"]: c["value"] for c in driver.get_cookies()}
    headers = {
        "User-Agent": driver.execute_script("return navigator.userAgent;"),
        "Referer": driver.current_url,  # certains serveurs vérifient le referer
    }

    response = requests.get(img_url, cookies=cookies, headers=headers, timeout=30)
    response.raise_for_status()

    with open(chemin, "wb") as f:
        f.write(response.content)
    print(f"Image enregistrée: {chemin}  ({len(response.content) // 1024} Ko)")


def getImagesFromURL(url, nb_total_pages, path_to_download):
    try:
        driver.get(url)

        for i in range(nb_total_pages):
            print(f"\nPage {i + 1}/{nb_total_pages}")
            time.sleep(1.2 + random.uniform(0, 0.5))  # laisser le temps à l'image de charger

            urls = extraire_urls_images_plein_format()

            if urls:
                telecharger_image(urls[-1], os.path.join(path_to_download, f"page_{i + 1:03d}.jpg"))
            else:
                print("Aucune image plein format détectée pour cette page.")

            # ── Passer à la page suivante ─────────────────────────────────────────
            try:
                btn_next = wait.until(
                    EC.element_to_be_clickable((By.CSS_SELECTOR, "button.fa-angle-right"))
                )
                driver.execute_script("arguments[0].click();", btn_next)
            except Exception:
                print("Bouton 'suivant' introuvable, arrêt.")
                break
    except Exception as e:
        print("="*50)
        print(url)
        print()
        print(e)
        print("="*50)

    # finally:
    #     driver.quit()



def flatten_keys(d):
    """Génère toutes les clés de tous les niveaux"""
    for key, value in d.items():
        yield key
        if isinstance(value, dict):
            yield from flatten_keys(value)

# for key in flatten_keys(BASE_URL):
#     print(key)

def iterate_keys(d, depth=3, current_depth=0):
    """Itère sur les clés à la profondeur spécifiée"""
    if current_depth == depth - 1:
        for key in d.keys():
            print(key)
    else:
        for value in d.values():
            if isinstance(value, dict):
                iterate_keys(value, depth, current_depth + 1)

def flatten(nested):
    flat = []
    for item in nested:
        if isinstance(item, list):
            flat.extend(flatten(item))
        else:
            flat.append(item)
    return flat

NB_TOTAL_PAGES = 0
DATES = []
date = []

# for key1, val1 in BASE_URL.items():
#     currentDir = os.path.join(currentDir, key1)
#     for key2, val2 in val1.items():
#         currentDir = os.path.join(currentDir, key2)
#         for key3, val3 in val2.items():
#             currentDir = os.path.join(currentDir, key3)
#             for key4, val4 in val3.items():
#                 if not ("432PO" in key4):
#                     for key5, val5 in val4.items():
#                         if not ("432PO" in key5):
#                             for key6, val6 in val5.items():
#                                 currentDir = os.path.join(currentDir, key6)
#                                 print(currentDir)
#                                 #print(key6)
#                                 NB_TOTAL_PAGES += val6["page_num"]
#                                 date = val6["date"].replace(" ", "").split(",")
#                                 DATES.append(date)
                                
#                                 currentDir = PATH_TO_DOWNLOAD
                                
#                         else:
#                             currentDir = os.path.join(currentDir, key5)
#                             print(currentDir)
#                             #print(key5)
#                             NB_TOTAL_PAGES += val5["page_num"]
#                             date = val5["date"].replace(" ", "").split(",")
#                             DATES.append(date)
                            
#                 else: 
#                     currentDir = os.path.join(currentDir, key4)
#                     print(currentDir)
#                     #print(key4)
#                     NB_TOTAL_PAGES += val4["page_num"]
#                     date = val4["date"].replace(" ", "").split(",")
#                     DATES.append(date)


def traverse_dict(d, current_path):
    """Traverse le dictionnaire récursivement en préservant l'arborescence"""
    global NB_TOTAL_PAGES, DATES
    
    for key, val in d.items():
        if isinstance(val, dict):
            if "page_num" in val:
                # DOCUMENT: on prend
                #doc_path = os.path.join(current_path, key)
                doc_path = current_path
                doc_name = str(key).replace("/", "-")
                repo_doc = os.path.join(doc_path, doc_name)
                # print(doc_name)
                os.makedirs(doc_path, exist_ok=True)  # Créer les répertoires si nécessaire
                os.makedirs(repo_doc, exist_ok=True)
                # with open(f"{os.path.join(doc_path, doc_name)}", "w") as f:
                #     f.write(doc_name)
                getImagesFromURL(val["url"], val["page_num"], repo_doc)

                # print(doc_path)
                NB_TOTAL_PAGES += val["page_num"]
                date_str = val["date"].replace(" ", "").split(",")
                DATES.append(date_str)
            else:
                # DOSSIER: continuer la récursion
                new_path = os.path.join(current_path, key)
                traverse_dict(val, new_path)

traverse_dict(BASE_URL, PATH_TO_DOWNLOAD)
                    
                    

DATES = flatten(DATES)

print("Il y a en tout", NB_TOTAL_PAGES, "pages.")

if PLOT_HISTO_DATES:
    #print(DATES)

    # Extraire toutes les années
    all_years = []
    for date_str in DATES:
        if '-' in date_str:
            start, end = date_str.split('-')
            start, end = int(start), int(end)
            all_years.extend(range(start, end + 1))
        else:
            all_years.append(int(date_str))

    counter = Counter(all_years)
    years = sorted(counter.keys())
    counts = [counter[year] for year in years]

    plt.figure(figsize=(14, 6))
    plt.bar(years, counts, width=0.8, color='steelblue', edgecolor='black')
    plt.xlabel('Année', fontsize=12)
    plt.ylabel('Nombre de documents (432PO/1)', fontsize=12)
    plt.title('Distribution des documents par année', fontsize=14)
    plt.xticks(rotation=45)
    plt.grid(axis='y', alpha=0.3)
    plt.tight_layout()
    plt.show()

    print(f"Période couverte: {min(years)} à {max(years)}")
    print(f"Année la plus représentée: {max(counter, key=counter.get)} ({max(counter.values())} documents)")
